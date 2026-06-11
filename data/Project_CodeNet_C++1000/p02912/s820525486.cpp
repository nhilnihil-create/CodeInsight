//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;

int main(){
    ll n,m; cin>>n>>m;
 priority_queue<int> pq;
    rep(i,n){
        ll a; cin>>a;
        pq.push(a);
    }
    for(ll i=0;i<m;i++){
        ll b=pq.top();
        pq.pop();
        pq.push(b/2);
    }
    ll ans=0;
    while(!pq.empty()){
        ans+=pq.top();
        pq.pop();
    }
    cout<<ans<<endl;

}

















































