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

int N;
int L[105];
int ans;

signed main(){
    cin>>N;
    for(int i=0;i<N;++i)cin>>L[i];
    sort(L,L+N);
    for(int i=0;i<N-2;++i){
        for(int j=i+1;j<N-1;++j){
            for(int k=j+1;k<N;++k){
                if(L[i]+L[j]>L[k]&&L[i]!=L[j]&&L[j]!=L[k]&&L[k]!=L[i]){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
}