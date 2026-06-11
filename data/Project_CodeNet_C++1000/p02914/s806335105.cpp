#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;


const int maxn = 1e6 + 5;


int n;
int f[61];

vector<ll> a;

ll basis[61];


void addVector(ll x) {
    for (int i=59; i>=0; i--) {
	if (!(x>>i&1)) continue;
	if (!basis[i]) {
	    basis[i] = x;
	    return;
	} else {
	    x ^= basis[i];
	}
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n;
    a.resize(n);
    
    for (int i=0; i<n; i++) {
	ll x;
	cin>>x;
	for (int j=0; j<60; j++) {
	    if (x>>j&1) {
		f[j]++;
	    }
	}
	a[i] = x;
    }

    ll res = 0;
    ll mask = 0;
    for (int i=0; i<60; i++) {
	if (f[i]%2) {
	    res += (1ll<<i);
	} else {
	    mask |= (1ll<<i);
	}
    }

    // keep bits that occ even # of times.
    for (ll& x: a) {
	x &= mask;
	addVector(x);
    }


    // max xor subset
    ll mx = 0;
    for (int i=59; i>=0; i--) {
	if (!basis[i]) continue;
	if (mx>>i&1) continue;
	mx ^= basis[i];
    }

    res += (2ll*mx);

    cout<<res<<endl;    
    return 0;
}
