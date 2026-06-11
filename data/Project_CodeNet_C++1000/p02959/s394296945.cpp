#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;

using _loop_int = int;
#define REP(i,n) for(_loop_int i=0; i<(_loop_int)(n); i++)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a); i<(_loop_int)(b); i++)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1; i>=(_loop_int)(a); i--)

#define CHMIN(a,b) (a)=min((a),(b))
#define CHMAX(a,b) (a)=max((a),(b))
#define ALL(v) (v).begin(),(v).end()

#define DEBUG(x) cerr<<#x<<": "<<(x)<<endl
#define DEBUG_VEC(v) cerr<<#v<<": ";REP(__i,(v).size())cerr<<((v)[__i])<<", ";cerr<<endl

const ll MOD = 1000000007ll;

int n;
int a[125252];
int b[125252];

int main(){
    scanf("%d",&n);
    REP(i,n+1)scanf("%d",a+i);
    REP(i,n)scanf("%d",b+i);
    ll ans = 0;
    REP(i,n){
        int sb = min(a[i], b[i]);
        a[i] -= sb;
        b[i] -= sb;
        ans += sb;
        sb = min(a[i+1], b[i]);
        a[i+1] -= sb;
        b[i] -= sb;
        ans += sb;
    }
    printf("%lld\n",ans);
    return 0;
}
