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

ll n,cnt,ans,a[ohara],b[ohara],c,d,tmp,tmpp,m,h,w,x,y,sum,pos,k;
ld doua;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
bool fl;
struct edge{int to,cost;};
ll now[ohara];
priority_queue<P> que;
ll res[ohara];

//-------------------------↓↓↓↓↓↓------------------------

//------ 自分を天才だと信じる ------

int main(void){
        cin.tie(0);
        cout.tie(0);
    ios::sync_with_stdio(false);

    cin>>n;
    rep(i,n)cin>>a[i];
    rep(i,n)cin>>b[i],now[i]=b[i];
    rep(i,n){
        ll hiku=(i==0 ? now[n-1] : now[i-1] )+(i==n-1 ? now[0] : now[i+1] );
        if(hiku<b[i])que.push({b[i],i});
    }
    while(1){
        if(que.empty())break;
        cnt++;
        if(cnt==10000000-10000)break;
        P X=que.top();
        que.pop();
        ll sco,ind;

        sco=X.fi;
        ind=X.se;
        //cout<<sco<<" "<<ind<<"\n";
        //scoをa[ind]までか引けるだけ引く
        ll hiku=(ind==0 ? now[n-1] : now[ind-1] )+(ind==n-1 ? now[0] : now[ind+1] );
        ll kaisuu=(sco-a[ind])/hiku;
        ans+=kaisuu;
        sco=sco-hiku*kaisuu;
        now[ind]=sco;
        //何をpushするか

        ll now_ind=(ind-1+n)%n;
        hiku=(now_ind==0 ? now[n-1] : now[now_ind-1] )+(now_ind==n-1 ? now[0] : now[now_ind+1] );
        if(hiku<now[now_ind])que.push({now[now_ind],now_ind});

        now_ind=(ind+1)%n;
        hiku=(now_ind==0 ? now[n-1] : now[now_ind-1] )+(now_ind==n-1 ? now[0] : now[now_ind+1] );
        if(hiku<now[now_ind])que.push({now[now_ind],now_ind});
    }
    rep(i,n){
        if(now[i]!=a[i]){
            Cout(-1);
            return 0;
        }
    }
    Cout(ans);
    return 0;
}
