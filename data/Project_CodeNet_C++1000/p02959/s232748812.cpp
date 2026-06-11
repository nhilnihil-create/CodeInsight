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
    vector<int> A(N+1),B(N);
    for(int i=0;i<=N;++i) cin>>A[i];
    for(int i=0;i<N;++i) cin>>B[i];
    ll ans=0;
    for(int i=0;i<N;++i){
        int num=min(A[i],B[i]);
        ans+=num;
        A[i]-=num;
        B[i]-=num;
        num=min(A[i+1],B[i]);
        ans+=num;
        A[i+1]-=num;
        B[i]-=num;
    }
    cout<<ans<<endl;
    return 0;
}