#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(c) (c).begin(),(c).end()
#define RALL(c) (c).rbegin(),(c).rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 10;

int K, N;

int main() {
    cin >> K >> N;
    vector<int> a(N+1);
    rep(i,N) cin >> a[i];
    a[N] = a[0] + K;
    int diff = 0;
    rep(i,N) chmax(diff, a[i+1] - a[i]);
    cout << K - diff << endl;
}