#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define ALL(x) (x).begin(),(x).end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
 
typedef pair<int,int> PI;
typedef pair<int,pair<int,int>> PII;
static const int INF=1010000000000000017LL;
static const double eps=1e-12;
static const double pi=3.14159265358979323846;
static const int dx[4]={1,-1,0,0};
static const int dy[4]={0,0,1,-1};
static const int ddx[8]={1,-1,0,0,1,1,-1,-1};
static const int ddy[8]={0,0,1,-1,1,-1,1,-1};
 
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

int H,N;
int A[1005];
int B[1005];

int dp[20005];

void init(){
    for(int i=0;i<20005;++i)dp[i]=INF;
}

signed main(){
    init();
    cin>>H>>N;
    for(int i=0;i<N;++i)cin>>A[i]>>B[i];
    dp[0]=0;
    for(int h=0;h<=H;++h){
        for(int i=0;i<N;++i){
            chmin(dp[h+A[i]],dp[h]+B[i]);
        }
    }
    int ans=INF;
    for(int h=H;h<20005;++h)chmin(ans,dp[h]);
    cout<<ans<<endl;
}
