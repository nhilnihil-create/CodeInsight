#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define until(x) while(!(x))
#define unless(x) if(!(x))
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define pc __builtin_popcount

const int mod = 998244353;
int ar[100005];
int cnt[100005];
int n;

int32_t main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
		cnt[ar[i]]++;
	}
	int ans = 1;
	if(ar[1]){
		ans = 0;
	}
	for(int i=2;i<=n;i++){
		ans *= cnt[ar[i]-1];
		ans %= mod;
	}
	cout<<ans;
}
