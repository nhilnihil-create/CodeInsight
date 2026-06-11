#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;





int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    int n;
    cin>>n;
    
    ll res = 0;

    for (int i=1; i<=n; i++) {
	res += (1ll*i*(i+1)/2);
    }
    
    for (int i=0; i<n-1; i++) {
	int u,v;
	cin>>u>>v;
	if (u>v) swap(u,v);
	ll cur = 1ll*u*(n-v+1);
	res -= cur;
    }

    cout<<res<<endl;    
    
    return 0;
}
