#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    int N; cin >> N;
    vector<int> alphabets(26);
    map<vector<int>, ll> m;
    rep(i, N){
        string s; cin >> s;
        alphabets.assign(26, 0);
        rep(j, 10){
            alphabets[s[j] - 'a']++;
        }
        m[alphabets]++;
    }
    ll ans = 0;
    for(auto x:m){
        ans += x.second * (x.second - 1) / 2;
    }
    cout << ans << endl;
}