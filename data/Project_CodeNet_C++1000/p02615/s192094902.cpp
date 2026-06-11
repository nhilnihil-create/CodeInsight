#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;
constexpr ll mod=1000000007;
constexpr int inf=1000000000;
constexpr ll linf=1000000000000000000;

int main(){
    int n;
    cin>>n;
    int a[n];
    rep(i,n)cin>>a[i];
    sort(a,a+n,greater<int>());
    priority_queue<int> pq;
    pq.push(a[0]);
    ll ans=0;
    for(int i=1;i<n;++i){
        ans+=pq.top();
        pq.pop();
        pq.push(a[i]);
        pq.push(a[i]);
    }
    cout<<ans<<endl;
}
