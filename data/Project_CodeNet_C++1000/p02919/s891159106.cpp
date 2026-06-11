#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin >> n;
    vector<int> g(n+1);
    for(int i=1;i<=n;i++){
        int p;cin >> p;
        g[p]=i;
    }
    multiset<int> ms;
    ms.insert(0);
    ms.insert(0);
    ms.insert(n+1);
    ms.insert(n+1);
    ll ans=0;
    for(ll i=n;i>=1;i--){
        ll l1,l2,r1,r2;
        auto itr=ms.lower_bound(g[i]);
        r1=*itr++;
        r2=*itr--;
        itr--;
        l2=*itr--;
        l1=*itr--;
        ans+=(g[i]-l2)*(r2-r1)*i;
        ans+=(l2-l1)*(r1-g[i])*i;
        ms.insert(g[i]);
    }
    cout << ans << endl;
}