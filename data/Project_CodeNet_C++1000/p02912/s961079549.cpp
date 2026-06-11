#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef vector<int> V;
typedef pair<int,int> P;
typedef vector<vector<int>> Graph;

int main() {
    set<pair<ll,int>> a;
    int n,m;
    cin >> n >> m;
    rep(i,n){
        ll A;
        cin >> A;
        a.insert(make_pair(A,i));
    }
    rep(i,m){
        auto l = a.end();
        --l;
        auto k = *l;
        //cout << k.first << " " << k.second << endl;
        a.erase(make_pair(k.first,k.second));
        a.insert(make_pair(k.first/2,k.second));
    }
    ll ans = 0;
    for(auto i : a){
        //cout << i.first << " " << i.second << endl;
        ans += i.first;
    }
    cout << ans << endl;
}