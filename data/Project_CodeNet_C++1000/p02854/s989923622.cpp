#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define ALL(v) (v.begin(),v.end())
#define COUT(x) cout<<(x)<<endl

int main() {
    int n;
    cin >> n;
    ll a[n],sum=0,tes=0;;
    REP(i,n){
        cin >> a[i];
        sum += a[i];
    }
    ll min1 = LINF;
    REP(i,n){
        tes += a[i];
        if(min1>abs(2*tes-sum))min1 = abs(2*tes-sum);
    }
    COUT(min1);
    return 0;
}