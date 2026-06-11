#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(c) (c).begin(),(c).end()
#define RALL(c) (c).rbegin(),(c).rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const ll INF = 1e18 + 10;

int N;

int main() {
    cin >> N;
    vector<int> S(N);
    rep(i,N) cin>>S[i];
    vector<int> v(N);
    ll v0_2 = 0;
    rep(i,N) {
        if (i&1) v0_2 -= S[i];
        else v0_2 += S[i];
    }
    
    v[0] = v0_2/2;
    rep(i,N-1) v[i+1] = S[i] - v[i];
    rep(i,N) cout << 2*v[i] << " ";
    cout << endl;
}