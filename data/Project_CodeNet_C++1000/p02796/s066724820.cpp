#include <iostream>
#include <utility>
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

int n;
int main() {
    cin >> n;
    vector<pair<int, int>> range(n);
    rep(i, 0, n){
        int a, b; cin >> a >> b;
        range[i] = {a+b, b+b};
    }

    sort(ALL(range));

    int nowPos = range[0].first;
    int ans = n;
    rep(i, 1, n){
        if (range[i].first - range[i].second < nowPos) ans--;
        else{
            nowPos = range[i].first;
        }
    }
    cout << ans << endl;
    return 0;
}
