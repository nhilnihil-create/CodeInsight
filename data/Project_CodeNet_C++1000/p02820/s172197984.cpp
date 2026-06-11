#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
bool ch[200010];ll ans;
	ll a[3];
void dep(char now){
	if(now=='r'){
		ans+=a[2];
	}
	else if(now=='s'){
		ans+=a[0];
	}
	else{
		ans+=a[1];
	}
}
int main() {
	ll n,k;
	cin>>n>>k;

	for(ll i=0;i<3;i++){
		cin>>a[i];
	}
	ch[0]=true;
	string s;
	cin>>s;
	for(ll i=0;i<n;i++){
		if(i-k>=0){
			if(s[i-k]==s[i]&&ch[i]){
				continue;
			}
			else{
				ch[i+k]=true;
				dep(s[i]);
			}
		}
		else{
			dep(s[i]);
			ch[i+k]=true;
		}
		//cout << ans<<" " <<i<<endl;
	}
	cout <<ans;
	// your code goes here
	return 0;
}