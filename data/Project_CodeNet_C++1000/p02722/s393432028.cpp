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
    ll N;cin>>N;
    if(N==2){
        cout<<1<<endl;
        return 0;
    }
    int ans=2;
    for(ll k=2;k*k<=N;++k){
        ll M=N;
        if(M%k==0){
            while(M%k==0){
                M/=k;
            }
            if(M%k==1) ans++;
        }else{
            if((M-1)%k==0) ans+=(k==(M-1)/k?1:2);
        }
    }
    cout<<ans<<endl;
    return 0;
}