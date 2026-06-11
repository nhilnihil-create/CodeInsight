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

int main(){
    int N;cin>>N;
    vector<pii> R(N);
    for(int i=0;i<N;++i){
        int X,L;cin>>X>>L;
        R[i]=pii(X+L,X-L);
    }
    sort(R.begin(),R.end());
    int ans=0;
    int t=-INF;
    for(int i=0;i<N;++i){
        if(t<=R[i].second){
            ans++;
            t=R[i].first;
        }
    }
    cout<<ans<<endl;
    return 0;
}