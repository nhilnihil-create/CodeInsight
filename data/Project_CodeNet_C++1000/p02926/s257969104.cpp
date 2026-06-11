// ※※※ 解答不能パターン. ※※※
// -> 以下のソースコードを復習する.
// rickytheta氏.
// https://atcoder.jp/contests/abc139/submissions/7268938
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
pair<long double, long double> es[125];

int main(){
    scanf("%d",&n);
    REP(i,n){
        long double x,y;
        scanf("%Lf%Lf",&x,&y);
        es[i] = make_pair(x,y);
    }
    sort(es,es+n,[&](pii a, pii b){
        return atan2(a.second, a.first) < atan2(b.second, b.first);
    });
    long double ans = 0;
    REP(i,n){
        long double dx=0, dy=0;
        REP(j,n){
            dx += es[(i+j)%n].first;
            dy += es[(i+j)%n].second;
            CHMAX(ans, dx*dx + dy*dy);
        }
    }
    printf("%.20Lf\n",sqrtl(ans));
    return 0;
}