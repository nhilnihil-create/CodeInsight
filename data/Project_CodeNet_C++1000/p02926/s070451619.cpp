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
    
ll n,cnt,a,b,c,d,tmp,tmpp,m,h,w,x[ohara],y[ohara],sum,pos,k,q;
ld doua;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
bool fl;
struct edge{int to,cost;};
pair<double,ll> p[ohara];
double ans;
    
//------ Believe yourself as a genius!!!!!! ------
    
int main(void){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>n;
    rep(i,n)cin>>x[i]>>y[i];
    rep(i,n){
        double theta;
        if(x[i]==0){
            if(y[i]==0){
                theta=0.0;
            }
            else if(y[i]>0){
                theta=90.0;
            }
            else{
                theta=270.0;
            }
        }
        else if(y[i]==0){
            if(x[i]>0){
                theta=0.0;
            }
            else{
                theta=180.0;
            }
        }
        else{
            theta=atan((double)abs(y[i])/(double)abs(x[i]));
            theta=theta*180.0/M_PI;
            if(x[i]<0&&y[i]>0){
                theta=180.0-theta;
            }
            else if(x[i]<0&&y[i]<0){
                theta=theta+180.0;
            }
            else if(x[i]>0&&y[i]<0){
                theta=360.0-theta;
            }
        }
        p[i]=m_p(theta,i);
    }
    sort(p,p+n);
    rep(i,n){
        p[i+n]=p[i];
    }
    rep(i,2*n){
        ll nowx=0,nowy=0;
        double now=0.0;
        U_MAP vi;
        rrep(j,i,2*n){
            if(vi[p[j].se]==1)break;
            vi[p[j].se]=1;
            nowx+=x[p[j].se];
            nowy+=y[p[j].se];
            now=max(now,sqrt(nowx*nowx+nowy*nowy));
        }
        ans=max(ans,now);
    }
    doublecout(ans);
    return 0;
}