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
    ll N=ii(), K=ii();
    vector<ll> P, C;
    REP(i,0,N){
        P.push_back(ii()-1);
    }
    REP(i,0,N){
        C.push_back(ii());
    }
    ll ret=LLONG_MIN;
    REP(i,0,N){
        ll all=0;
        ll n=0;
        ll c=i;
        ll k=K;
        REP(j,0,N){
            c=P[c];
            all+=C[c];
            n++;
            if(c==i) break;
        }
        ll r=0;
        if(k/n-1>0){
            if(all>0){
                r=(k/n-1)*all;
            }
            k-=(k/n-1)*n;
        }
        REP(j,0,k){
            c=P[c];
            r+=C[c];
            ret=max(ret,r);
        }
    }
    oie(ret);
    return 0;
}