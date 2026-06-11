#include <bits/stdc++.h>
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,n) FOR(i,0,n)
#define all(x) (x).begin(),(x).end()
#define PRINT(V) cout << V << "\n"
#define SORT(V) sort((V).begin(),(V).end())
#define RSORT(V) sort((V).rbegin(), (V).rend())
using namespace std;
using ll = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1e13;
typedef pair<ll,ll> P;
int main(){
    ll t1,t2;
    ll a1,a2;
    ll b1,b2;
    cin >> t1 >> t2;
    cin >> a1 >> a2;
    cin >> b1 >> b2;
    ll ans = 0;
    if (t1*a1+t2*a2 == t1*b1+t2*b2){
        PRINT("infinity");
    }
    else{
        ll k = abs(t1*a1+t2*a2-t1*b1-t2*b2);
        if (t1*a1+t2*a2 > t1*b1+t2*b2){
            ll a = t1*a1 - t1*b1;
            if (a >= 0) PRINT(0);
            else{
                if (abs(a)%k == 0) PRINT(2*(abs(a)/k));
                else PRINT(2*(abs(a)/k)+1);
            }
        }
        else{
            ll a = t1*b1 - t1*a1;
            if (a >= 0) PRINT(0);
            else{
                if (abs(a)%k == 0) PRINT(2*(abs(a)/k));
                else PRINT(2*(abs(a)/k)+1);
            }
        }
    }
}