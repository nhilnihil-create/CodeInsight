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

int N,K;
int P[5005];
int C[5005];
int v[5005];
bool visited[5005];
bool loop[5005];
PI loopCost[5005];
int ans=-INF;

void init(){
    for(int i=0;i<5005;++i){
        loop[i]=false;
        loopCost[i]=PI(-INF,-INF);
    }
}

void cal(int n){
    if(visited[n]){
        loop[n]=true;
        return;
    }
    visited[n]=true;
    cal(P[n]);
}

signed main(){
    init();
    cin>>N>>K;
    for(int i=0;i<N;++i){
        cin>>P[i];
        P[i]--;
    }
    for(int i=0;i<N;++i)cin>>C[i];
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j)visited[j]=false;
        cal(i);
    }
    for(int i=0;i<N;++i){
        if(!loop[i])continue;
        int p=i;
        int cost=0;
        int cnt=0;
        while(true){
            cost+=C[p];
            p=P[p];
            cnt++;
            if(p==i)break;
        }
        loopCost[i]=PI(cost,cnt);
    }
    for(int i=0;i<N;++i){
        int res=0;
        int cnt=0;
        int p=i;
        bool skip=false;
        while(cnt<K){
            int remain=K-cnt;
            if(loop[p]&&loopCost[p].second<remain&&!skip){
                if(loopCost[p].first>0){
                    res+=(remain/loopCost[p].second-1)*loopCost[p].first;
                    cnt+=(remain/loopCost[p].second-1)*loopCost[p].second;
                    chmax(ans,res);
                }
                else {
                    cnt=K-loopCost[p].second;
                }
                skip=true;
            }
            else {
                res+=C[p];
                p=P[p];
                cnt++;
                chmax(ans,res);
            }
        }
        chmax(ans,res);
    }
    cout<<ans<<endl;
}