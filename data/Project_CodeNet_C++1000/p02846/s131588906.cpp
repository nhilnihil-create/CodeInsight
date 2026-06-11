#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(ll i = 0; i<(ll)(n); i++)
#define REPS(i,n) for (ll i = 1; i<=(ll)(n); i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define pb push_back
#define MOD 1000000007
#define MOD2 998244353
#define PI 3.141592653
#define INF 100000000000000 //14

int main(){
    ll t1, t2, a1, a2, b1, b2; cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    ll a = t1*a1+t2*a2;
    ll b = t1*b1+t2*b2;
    ll af = t1*a1;
    ll bf = t1*b1;
    if (a>b&&af>=bf){
        cout << 0 << endl;
    }
    else if (a>b&&af<bf){
        ll z = (bf-af)/(a-b);
        if ((bf-af)==(a-b)*z) cout << 2*z << endl;
        else cout << 2*z+1 << endl;

    }
    else if (a==b){
        cout << "infinity" << endl;
    }
    else if (a<b&&af<=bf){
        cout << 0 << endl;
    }
    else{
        ll z = (af-bf)/(b-a);
        if ((af-bf)==(b-a)*z) cout << 2*z << endl;
        else cout << 2*z+1 << endl;
    }
}