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

const int mod=1000000007;

int modPow(int a, int n) {
    if(n==1)return a%mod;
    if (n%2==1)return(a*modPow(a,n-1))%mod;
    int t=modPow(a,n/2);
    return (t*t)%mod;
}

int N,K;
int f[100005];


signed main(){
    cin>>N>>K;
    for(int i=K;i>=1;--i){
        f[i]=modPow(K/i,N);
        for(int j=2;j<=K;++j){
            if(i*j>K)break;
            f[i]-=f[i*j];
            f[i]=(f[i]+mod)%mod;
        }
    }
    int ans=0;
    for(int i=1;i<=K;++i){
        ans+=i*f[i];
        ans%=mod;
    }
    cout<<ans<<endl;
}