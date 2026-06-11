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
int a[1252][1252];
int enemy[1252];
int head[1252];

int main(){
    scanf("%d",&n);
    REP(i,n)REP(j,n-1)scanf("%d",&a[i][j]),a[i][j]--;
    int ans = 0;
    while(true){
        ans++;
        REP(i,n)if(head[i]!=n-1){
            enemy[i] = a[i][head[i]];
        }
        bool upd = false;
        REP(i,n)if(head[i]!=n-1 && enemy[enemy[i]]==i){
            head[i]++;
            upd = true;
        }
        if(!upd){
            puts("-1");
            return 0;
        }
        if(count(head,head+n,n-1)==n){
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}