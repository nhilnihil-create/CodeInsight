#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<int,int>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N;
    cin>>N;
    vector<vector<int>> v(N,vector<int>(2));
    rep(i,N) cin>>v[i][0]>>v[i][1];
    vector<vector<int>> w(N,vector<int>(2));
    rep(i,N) {
        w[i][0] = v[i][0] + v[i][1];
        w[i][1] = v[i][0] - v[i][1];
    }
    sort(w.begin(),w.end());
    int ans = 0;
    int t = -INF;
    rep(i,N){
        if(t<=w[i][1]){
            ans++;
            t = w[i][0];
        }
    }
    cout<<ans<<endl;
}