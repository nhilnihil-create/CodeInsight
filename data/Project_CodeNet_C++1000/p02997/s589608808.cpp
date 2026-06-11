#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000

typedef pair<int, int> P;
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    int upper = (N - 1) * (N - 2) / 2;
    if(upper < K) {
        cout << "-1" << endl;
        return 0;
    }
    vector<P> v;
    rep(i, N - 1) {
        v.push_back({1, i + 2});
    }
    int diff = upper - K;
    int l = 2, r = 3;
    rep(i, diff) {
        v.push_back({l, r});
        r++;
        if(r > N) {
            l++;
            r = l + 1;
        }
    }
    cout << v.size() << endl;
    rep(i, v.size()) {
        cout << v[i].first << " " << v[i].second << endl;
    }

    return 0;
}
