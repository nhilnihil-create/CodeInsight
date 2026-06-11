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

int N,M,Q;
int A[55],B[55],C[55],D[55];
vector<int> tmp;
vector<vector<int>> v;

void dfs(int n,int p){
    if(n==N){
        v.push_back(tmp);
        return ;
    }
    for(int i=p;i<=M;++i){
        tmp.push_back(i);
        dfs(n+1,i);
        tmp.pop_back();
    }
}

signed main(){
    cin>>N>>M>>Q;
    for(int i=0;i<Q;++i){
        cin>>A[i]>>B[i]>>C[i]>>D[i];
        A[i]--,B[i]--;
    }
    dfs(0,1);
    int ans=0;
    for(auto u:v){
        int res=0;
        for(int i=0;i<Q;++i){
            //cout << u[i] << " ";
            if(u[B[i]]-u[A[i]]==C[i])res+=D[i];
        }
        //cout << endl;
        //cout << res << endl;
        chmax(ans,res);
    }
    cout<<ans<<endl;
}