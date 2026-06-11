#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n,m;
    cin>>n>>m;

    priority_queue<int> pq;
    rep(i,n){
        int a;
        cin>>a;
        pq.push(a);
    }

    rep(i,m){
        int x=pq.top();
        pq.pop();
        x/=2;
        pq.push(x);
    }

    ll ans=0;
    rep(i,n){
        int x=pq.top();
        pq.pop();
        ans+=x;
    }

    cout<<ans<<endl;
}
