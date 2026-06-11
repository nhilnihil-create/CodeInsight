#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF=1e9,MOD=1e9+7,ohara=1e6+10;
const ll LINF=1e18;
using namespace std;
    
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(int i=(a);i<(b);i++)
#define rrrep(i,a,b) for(int i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define Size(n) (n).size()
#define Cout(x) cout<<(x)<<endl
#define doublecout(a) cout<<fixed<<setprecision(15)<<a<<endl;
#define Cerr(x) cerr<<(x)<<endl
#define fi first
#define se second
#define P pair<ll,ll> 
#define m_p make_pair
#define V vector<ll> 
#define U_MAP unordered_map<ll,ll>
#define pq priority_queue<ll>
#define rpq priority_queue<ll,vector<ll>,greater<ll>>
#define p_b push_back
    
ll n,cnt,ans,a,b,c,d,tmp,tmpp,m,h,w,x,y,sum,pos,k;
ld doua;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
bool fl;
struct edge{int to,cost;};
ll tate[1000][1000];//各頂点に配布する二進
ll rui[ohara];
    
//-------------------------↓↓↓↓↓↓------------------------
    
//------ 自分を天才だと信じる ------
    
int main(void){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>n;

    cnt=2;
    rui[0]=1;
    rrep(i,1,46){
        rui[i]=cnt;
        cnt*=2;
    }

    rep(i,n){
        tmp=i;
        while(1){
            rrrep(j,45,0){
                if(rui[j]<=tmp){
                    tmp-=rui[j];
                    tate[i][j+1]++;
                    break;
                }
            }
            if(tmp==0)break;
        }
    }
    rep(i,n){
        rrep(j,i+1,n){
            rep(k,46){
                if(tate[i][k]!=tate[j][k]){
                    if(j!=n-1)cout<<k<<" ";
                    else Cout(k);
                    break;
                }
            }
        }
    }
    return 0;
}