#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
ll ch[10][10];
int main() {
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++){
		ll now=i;
		ll b=now%10;
	//	cout << now/10<<" ";
		while((now/10)!=0){
			now/=10;
		}
		ll a=now;
		ch[a][b]++;
	//	cout << i<< " "<< a<<" "<< b<<endl;
	}
	ll cnt=0;
	for(ll i=1;i<10;i++){
		for(ll j=1;j<10;j++){
			cnt+=ch[i][j]*ch[j][i];
		}
	}
	cout <<cnt;
	// your code goes here
	return 0;
}