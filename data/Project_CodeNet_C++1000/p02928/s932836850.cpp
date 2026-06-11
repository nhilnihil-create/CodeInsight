#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define ALL(v) ((v).begin(),(v).end())
#define COUT(x) cout<<(x)<<"\n"

int main(){
    ll n,k;
    cin >> n >> k;
    vector<int> vec(n);
    REP(i,n)cin >> vec[i];
    vector<ll> kazu1(n,0);
    vector<ll> kazu2(n,0);
    REP(i,n){
        FOR(j,i+1,n){
            if(vec[i]>vec[j])kazu1[i]++;
        }
        REP(m,n){
            if(vec[i]>vec[m])kazu2[i]++;
        }
    }
    ll test= (k*(k-1)/2)%MOD;
    ll ans = 0;
    REP(i,n){
        ans += (kazu1[i]*k+kazu2[i]*test)%MOD;
        ans %= MOD;
    }
    COUT(ans);
    return 0;
}