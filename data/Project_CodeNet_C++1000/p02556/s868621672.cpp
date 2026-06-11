#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N;
    cin >> N;
    vector<int> h(N),w(N);
    rep(i,N){
        int x,y;
        cin >> x >> y;
        h[i]=x+y;
        w[i]=x-y;
    }
    sort(h.begin(),h.end());
    sort(w.begin(),w.end());
    ll ans = max(h[N-1]-h[0],w[N-1]-w[0]);
    cout << ans << endl;
    return 0;
}