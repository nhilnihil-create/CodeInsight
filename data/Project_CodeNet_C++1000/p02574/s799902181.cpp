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

vector<int> smallest_prime_factors(int n){

    vector<int> spf(n+1);
    for (int i=0;i<=n;i++)spf[i]=i;
    for (int i=2;i*i<=n;i++){
        // 素数だったら
        if (spf[i]==i){
            for (int j=i*i;j<=n;j+=i){
                // iを持つ整数かつまだ素数が決まっていないなら
                if (spf[j]==j) {
                    spf[j]=i;
                }
            }
        }
    }
    return spf;
}

vector<int> factolization(int x, vector<int> &spf) {
    vector<int> ret;
    while (x!=1) {
        ret.push_back(spf[x]);
        x/=spf[x];
    }
    sort(ret.begin(),ret.end());
    ret.erase(unique(ret.begin(),ret.end()),ret.end());
    return ret;
}

int N;
bool used[1000005];

bool pairwise_coprime=true;
bool setwise_coprime=true;

signed main(){
    cin>>N;
    auto spf=smallest_prime_factors(1000000);
    int g;
    for(int i=0;i<N;++i){
        int a;
        cin>>a;
        auto res=factolization(a,spf);
        for(auto z:res){
            if(used[z])pairwise_coprime=false;
            used[z]=true;
        }
        if(i==0)g=a;
        else g=__gcd(a,g);
    }
    if(pairwise_coprime)cout<<"pairwise coprime"<<endl;
    else if(g==1)cout<<"setwise coprime"<<endl;
    else cout<<"not coprime"<<endl;
}