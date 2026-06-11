#include<bits/stdc++.h>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1001001001;
using namespace std;


int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n) a[i]--;
    vector<int> s(n+1);
    rep(i, n) {
        s[i+1] = (s[i] + a[i]) % k;
    }
    map<int, int> mp;
    ll ans = 0;
    queue<int> q;
    rep(j, n+1) {
        ans += mp[s[j]];
        mp[s[j]]++;
        q.push(s[j]);
        if (q.size() == k) {
            mp[q.front()]--;
            q.pop();
        }
    }

    cout << ans << endl;
}