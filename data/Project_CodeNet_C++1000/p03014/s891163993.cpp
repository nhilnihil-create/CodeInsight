#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG2(x,y) cout<<#x<<": "<<x<<" "<<#y<<": "<<y<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define DEBUG_ARR(v,n) cout<<#v<<":";REP(i,n)cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

const ll MOD = 1000000007ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true; }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T>
void DEBUG_DP(T* viewdp, int ilen, int jlen){
    REP(i,ilen){
        REP(j,jlen){
            if(viewdp[i][j] != -1)
                printf("[% 4d]", viewdp[i][j]);
            else
                printf("[    ]");
        }
        puts("");
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int h,w;
    cin>>h>>w;
    vector<string> m(h+1);
    REP(i,h){
        cin>>m[i];
        m[i] += "#";
    }
    vector<vi> cs(h+1, vi(w+2,0));

    //yoko
    REP(i,h) REP(j,w){
        if(m[i][j]=='.'){
            cs[i][j+1] = cs[i][j] + 1;
        }
    }

    //tate
    int ans = 0;
    FORR(j,1,w+1){
        int yokomx = 1;
        int tatecnt = 0;
        REP(i,h) {
            //DEBUG2(i,j);
            if(cs[i][j]!=0) chmax(cs[i][j], cs[i][j+1]);
            chmax(yokomx, cs[i][j]);

            if(m[i][j-1]=='.'){
                tatecnt += 1;
            }else{
                ans = max(ans, tatecnt + yokomx - 1);
                tatecnt = 0;
                yokomx = 1;
            }
            // DEBUG2(tatecnt, yokomx);
            // DEBUG(ans);
        }

        ans = max(ans, tatecnt + yokomx-1);
    }

    // REP(ji,h){
    //     DEBUG_VEC(cs[ji]);
    // }
    cout << ans << endl;
    return 0;
}