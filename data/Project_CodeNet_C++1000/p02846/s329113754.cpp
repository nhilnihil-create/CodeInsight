#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    ll T1,T2,A1,A2,B1,B2;
    cin >> T1 >> T2;
    cin >> A1 >> A2;
    cin >> B1 >> B2;
    A1 *= T1;
    A2 *= T2;
    B1 *= T1;
    B2 *= T2;
    if(A1 < B1 && A1 + A2 < B1 + B2 || A1 > B1 && A1 + A2 > B1 + B2){
        cout << 00 << endl;
        return 0;
    }else if(A1+A2 == B1+B2){
        cout << "infinity" << endl;
        return 0;
    }
    ll sd = abs(A1-B1);
    ll dd = abs(A1+A2-B1-B2);
    ll r = sd % dd;
    ll q = (sd) / dd;
    q *= 2;
    if(r != 0) q++;
    cout << q << endl;
}