#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
ll ch[100010];
int main() {
	ll n,k,R,S,P;
	cin>>n>>k>>R>>S>>P;
	string s;
	cin>>s;
	for(ll i=0;i<n;i++){
		char now;
		cin>>now;
		if(i>=k){
			if(s[i]==s[i-k]&&ch[i-k]!=0){
				continue;
			}
		}
		if(s[i]=='s'){
			ch[i]=R;
		}
		else if(s[i]=='p'){
			ch[i]=S;
		}
		else{
			ch[i]=P;
		}
	}
	ll cnt=0;
	for(ll i=0;i<n;i++){
		cnt+=ch[i];
	}
	cout <<cnt;
	// your code goes here
	return 0;
}