#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;
const ll inf = 2e18;


int n;
ll a[maxn];
ll racc[maxn];

ll mul(ll x, ll y) {
    if (x>inf/y) {
	return inf;
    }
    return x*y;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n;

    if (n==0) {
	int x; cin>>x;
	if (x != 1) out(-1);
	out(1);
    }
    
    n++;
    
    for (int i=0; i<n; i++) {
	cin>>a[i];
    }


    for (int i=n-1; i>=0; i--) {
	racc[i]=a[i]+racc[i+1];
    }

    if (a[0]>0) {
	out(-1);
    }

    ll res = 1;
    ll par = 1;
    
    for (int i=1; i<n; i++) {
	ll maxp = mul(par, 2);
	if (a[i]>maxp) {
	    out(-1);
	}
	maxp -= a[i]; // make leaves
	res += a[i];
	maxp = min(maxp, racc[i+1]);
	res += maxp;
	par = maxp;

	//cout<<i<<": "<<res<<endl;
    }


    cout<<res<<endl;    
    return 0;
}
