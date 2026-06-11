#include<bits/stdc++.h>
#define ull unsigned long long
#define pi acos(-1)
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f;
const ll maxn = 1e7+5;
const ll mod = 1e9+7;
ll a[2010]={0,0,0,1,1};
int main(){
	int s;
	cin>>s;
	for(int i=4;i<=s;i++) a[i]=(a[i-1]%mod+a[i-3]%mod)%mod;
	cout<<a[s]<<'\n'; 
	return 0;
}