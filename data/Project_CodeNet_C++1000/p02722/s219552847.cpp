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
vector<ll> diviser(ll X){
    vector<ll> res;
    for(ll i=1;i*i<=X;++i){
        if(X%i==0){
            res.push_back(i);
            if(i!=X/i) res.push_back(X/i);
        }
    }
    sort(res.begin(),res.end());
    return res;
}
int main(){
    ll N;cin>>N;
    auto res1=diviser(N-1);
    auto res2=diviser(N);
    ll ans=(int)res1.size()-1;
    for(auto it:res2){
        if(it==1) continue;
        ll M=N;
        while(M%it==0) M/=it;
        if(M%it==1) ans++;
    }
    cout<<ans<<endl;
    return 0;
}