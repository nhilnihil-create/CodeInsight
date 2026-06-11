#include<bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
const int MOD=1e9+7;
int n,a=1,b=1,c=1;
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;i++){
		a*=10,a%=MOD;
		b*=9,b%=MOD;
		c*=8,c%=MOD;
	}
	a+=MOD+MOD;
	int ans=(a-b-b+c)%MOD;
	cout<<ans;
	re 0;
}