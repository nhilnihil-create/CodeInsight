#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define len(x) (int)(x.size())
#define all(vs) vs.begin(), vs.end()
using ii = pair<int, int>;
using ll = long long;
#define int long long
const int mod = 1e9+7;

int mod_exp(int a, int b){
    if(b == 0) return 1;
    int c = mod_exp(a, b/2);
    c = (c*c)%mod;
    if(b%2 != 0) c=(c*a)%mod;
    return c;
}
int mod_inv(int a){
	return mod_exp((a%mod), mod-2);
}
#define MAXN 1000009
int fat[MAXN];
void init(){
    fat[0] = 1;
    for(int i=1; i<MAXN; ++i)
        fat[i]=(i*fat[i-1])%mod;
}
int32_t main(){
	init();
	ios::sync_with_stdio(0);	
	int n, a, b;
	cin >> n >> a >> b;
	int ans = mod_exp(2, n);
	ans -= 1;
	int res = 1, k = n;
	for(int i=0; i<a; ++i)
		res *=k, res%=mod, --k;
	res = (res*mod_inv(fat[a]))%mod;
	ans -=res;
	res = 1; k = n;
	for(int i=0; i<b; ++i)
		res *=k, res%=mod, --k;
	res = (res*mod_inv(fat[b]))%mod;
	ans -= res;
	if(ans<0)
		ans = ((mod-1)*(-ans))%mod;
	ans %=mod;
	cout << ans << endl;
}
