#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	string S;
	cin >> S;
	vector<string> v;
	v.push_back(S.substr(0,1));
	S = S.substr(1,S.size()-1);
	while (S.size()>0) {
		string l, r;
		for (int i = 1; i <= S.size(); i++) {
			l = S.substr(0,i);
			r = S.substr(i,S.size()-i);
			if (l != v.back()) {
				v.push_back(l);
				break;
			}
		}
		S = r;
	}
	cout << v.size() << endl;
	return 0;
}
