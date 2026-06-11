#include <bits/stdc++.h>
using namespace std;
#include <math.h> 
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
	ll ch[9][9];
int main() {
	ll n;cin>>n;
	for(ll i=1;i<=n;i++){
		ll b=i%10;
		if(b==0){
			continue;
		}
		ll now=i;
		while(now/10!=0){
			now/=10;
		}
		b--;now--;
		ch[now][b]++;
	}
	ll ans=0;
	for(ll i=0;i<9;i++){
		for(ll j=0;j<9;j++){
			ans+=ch[i][j]*ch[j][i];
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}