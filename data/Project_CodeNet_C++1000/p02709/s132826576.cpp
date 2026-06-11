#include <bits/stdc++.h>
 
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef tuple<ll, ll, ll> ti;
ll mod=1E9+7;
 
#define REP(a,b,c) for(ll a=(b);a<(c);a++)
#define PER(a,b,c) for(ll a=(b);a>=(c);a--)

ll ii(){ ll x; cin >> x; return x; }
string is(){ string x; cin >> x; return x; }
double id(){ double x; cin >> x; return x; }
void oi(ll x){ cout << x; }
void od(ld x){ cout << fixed << setprecision(10) << x; }
void os(string x){ cout << x; }
void oe(){ cout << endl; }
void oie(ll x){ oi(x); oe(); }
void ode(ld x){ od(x); oe(); }
void ose(string x){ os(x); oe(); }

ll dp[3000][3000];
int main(){
    ll N=ii();
    vector<pii> A;
    REP(i,0,N) A.push_back(make_pair(ii(),i));
    sort(A.rbegin(), A.rend());

    REP(i,0,N){
        REP(j,0,i+1){
            dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+A[i].first*abs(A[i].second-j));
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]+A[i].first*abs(A[i].second-(N-1-i+j)));
        }
    }

    ll ret=0;
    REP(j,0,N+1){
        ret=max(dp[N][j],ret);
    }
    oie(ret);
 
    return 0;
}