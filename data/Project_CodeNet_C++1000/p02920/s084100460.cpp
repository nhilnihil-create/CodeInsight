#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
using namespace std;
const int MAXN=270000;
int n,tot;
int MX=0;
multiset<int> s;
vector<int> t;

int main()

{
	ios::sync_with_stdio(false);
	cin>>n;
	tot=1<<n;
	for (int i=1;i<=tot;i++){
		int tmp;
		cin>>tmp;
		MX=max(tmp,MX);
		s.insert(tmp);
	}

	t.push_back(MX);
	s.erase(s.find(MX));

	for (int i=0;i<n;i++){
		vector<int> tmp;
		for (int j=0;j<t.size();j++){
			int now=t[j];
			auto yyf=s.lower_bound(now);
			if (yyf==s.begin()){
				cout<<"No"<<endl;
				return 0;
			}
			yyf--;
			tmp.push_back(*yyf);
			s.erase(yyf);
		}

		for (int j=0;j<tmp.size();j++){
			t.push_back(tmp[j]);
		}
	}

	cout<<"Yes"<<endl;
	return 0;
}