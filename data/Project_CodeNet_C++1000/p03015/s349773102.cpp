#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> p;
typedef long long ll;
typedef pair<ll,ll> pll;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e9;
const ll MOD=1e9+7;
struct edge{
    int to;
    int cost;
};

int main(){
    string L;cin>>L;
    int N=(int)L.size();
    ll DP[N+1][2];
    for(int i=0;i<=N;++i){
        for(int j=0;j<2;++j){
            DP[i][j]=0;
        }
    }
    DP[0][0]=1;
    for(int i=0;i<N;++i){
        if(L[i]=='0'){
            DP[i+1][0]=DP[i][0];
            DP[i+1][1]=DP[i][1]*3%MOD;
        }else{
            DP[i+1][0]=DP[i][0]*2%MOD;
            DP[i+1][1]=(DP[i][0]+DP[i][1]*3)%MOD;
        }
    }
    cout<<(DP[N][0]+DP[N][1])%MOD<<endl;
    return 0;
}