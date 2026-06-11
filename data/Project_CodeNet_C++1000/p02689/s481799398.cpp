#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define endl "\n"
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
#define INF 1e9
#define DEBUG(x) cout<<"debug: "<<x<<endl

int n, m;
vector<int> graph[100010];
int main() {
    cin >> n >> m;
    vector<int> h(n);
    rep(i, 0, n) cin >> h[i];
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        a--;b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int ans = 0;
    rep(i, 0, n){
        int nh = h[i];
        int maxh = 0;
        for(auto x : graph[i]){
            maxh = max(maxh, h[x]);
        }
        if(nh > maxh) ans++;
    }

    cout << ans << endl;
    return 0;
}
