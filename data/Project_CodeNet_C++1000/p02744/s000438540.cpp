#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	if(n==1){
		cout << "a";
		return 0;
	}
	vector<string>s[10];
	s[0].push_back("a");
	for(ll i=1;i<10;i++){
		for(ll j=0;j<s[i-1].size();j++){
			string now=s[i-1][j];
			ll last=0;
			for(ll k=0;k<now.size();k++){
				last=max(last,ll(now[k]-'a'));
			}
			//cout <<i<<j<<last;
			for(ll k=0;k<=last+1;k++){
				char next='a'+k;
			//	cout << next<<endl;
				s[i].push_back(now+next);
				if(i+1==n){
					cout <<now+next<<endl;
				}
			}
		}
	}
	// your code goes here
	return 0;
}