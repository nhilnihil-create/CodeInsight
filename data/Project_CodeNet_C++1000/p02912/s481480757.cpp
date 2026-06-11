#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const ll MOD=1e9+7;
const int INF=1e9;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false); 

    int n,m;
    cin >> n >> m;
    priority_queue<double> pq;
    rep(i,n) {
        int a;
        cin >> a;
        pq.push(1.0*a);
    } 
    rep(i,m) {
        double d=pq.top();
        pq.pop();
        pq.push(d*0.5);
    }
    ll ans=0;
    while (!pq.empty()) {
        double d=pq.top();
        pq.pop();
        ans+=ll(d);
    }
    cout << ans << endl;

    return 0;
}
