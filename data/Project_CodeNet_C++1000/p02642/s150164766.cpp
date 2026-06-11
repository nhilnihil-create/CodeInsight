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
typedef pair<int,pii> pipii;
typedef long long ll;
typedef pair<ll,ll> pll;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e18;
const ll MOD=1e9+7;
struct edge{
    int to;
    int cost;
};

int main(){
    int N;cin>>N;
    vector<int> A(N),cnt(1e6+1,0);
    vector<bool> ok(1e6+1,false);
    for(int i=0;i<N;++i){
        cin>>A[i];
        cnt[A[i]]++;
        ok[A[i]]=true;
    }
    for(int i=0;i<=1e6;++i)if(ok[i]){
        if(cnt[i]>=2) ok[i]=false;
        for(int j=i*2;j<=1e6;j+=i) ok[j]=false;
    }
    int ans=0;
    for(int i=0;i<=1e6;++i)if(ok[i]) ans++;
    cout<<ans<<endl;
    return 0;
}