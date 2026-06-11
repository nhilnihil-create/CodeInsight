#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    int N; cin >> N;
    map<string, int> m;
    rep(i, N){
        string str;
        cin >> str;
        sort(all(str));
        m[str]++;
    }
    ll ans = 0;
    for(auto x:m){
        // cout << x.first << " " << x.second << endl;
        ans += x.second*(x.second - 1LL) / 2;
    }
    cout << ans << endl;
}
