#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define INTINF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 
 
int main() {
	int ans = 0;
	int tmp = 0;
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int> > p;
	priority_queue<int, vector<int> > np;
	REP(i, n){
		cin >> tmp;
		if(tmp > 0) p.push(tmp);
		else np.push(tmp);
	}
	vector<pair<int, int>> seq;
	if(np.size()>0){
		tmp = np.top();
		np.pop();
	}
	else{
		tmp = p.top();
		p.pop();
	}
	while(p.size()>0 || np.size()>0){
		if(p.size() == 1){
			seq.push_back(make_pair(p.top(), tmp));
			tmp = p.top() - tmp;
			p.pop();
		}
		else if(p.size() > 1){
			seq.push_back(make_pair(tmp, p.top()));
			tmp -= p.top();
			p.pop();
		}
		else{
			seq.push_back(make_pair(tmp, np.top()));
			tmp -= np.top();
			np.pop();
		}
	}
	cout << tmp << endl;
	REP(i, n-1) cout << seq[i].first <<" " << seq[i].second << endl;
}