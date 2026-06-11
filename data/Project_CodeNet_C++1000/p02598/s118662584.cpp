#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef tuple<ll, ll, ll> ti;
 
#define REP(a,b,c) for(ll a=b;a<(c);a++)
#define PER(a,b,c) for(ll a=b;a>=(c);a--)
 
inline ll ii(){ ll x; cin >> x; return x; }
inline string is(){ string x; cin >> x; return x; }
inline ld id(){ ld x; cin >> x; return x; }
inline void oi(ll x){ cout << x; }
inline void od(ld x){ cout << fixed << setprecision(10) << x; }
inline void os(string x){ cout << x; }
inline void oe(){ cout << endl; }
inline void oie(ll x){ oi(x); oe(); }
inline void ode(ld x){ od(x); oe(); }
void ose(string x){ os(x); oe(); }

int main(){
    ll N=ii();
    ll K=ii();
    vector<ll> A;
    REP(i,0,N){
        A.push_back(ii());
    }
    ll l=1,r=10E9;
    while(r>l){
        ll m=(l+r)/2;
        ll t=0;
        REP(i,0,N){
            t+=max((A[i]+(m-1))/m-1,(ll)0);
        }
        if(t>K){
            l=m+1;
        }else{
            r=m;
        }
    }
    oie(r);
    return 0;
}
