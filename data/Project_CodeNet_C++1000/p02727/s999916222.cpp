#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

void code() {
    ll x,y,a,b,c;
    cin>>x>>y>>a>>b>>c;
    ll ans=0;
    vector<ll> A(a);
    vector<ll> B(b);
    vector<ll> C(c);
    for(ll i=0; i<a; i++) {
        cin>>A[i];
    }
    for(ll i=0; i<b; i++) {
        cin>>B[i];
    }
    for(ll i=0; i<c; i++) {
        cin>>C[i];
    }
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    sort(C.rbegin(), C.rend());
    vector<ll> tot;
    for(ll i=0; i<x; i++)
        tot.push_back(A[i]);
    for(ll i=0; i<y; i++)
        tot.push_back(B[i]);
    for(ll i=0; i<c; i++)
        tot.push_back(C[i]);
    sort(tot.rbegin(), tot.rend());
    for(ll i=0; i<(x+y); i++)
        ans+=tot[i];
    cout << ans << "\n";
}

signed main() {
    std::ios_base::sync_with_stdio(false);
    ll t=1;
    // cin>>t;
    for(ll i=0; i<t; i++) {
        code();
    }
}
