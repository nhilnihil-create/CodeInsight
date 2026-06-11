//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    int n, k;
    cin >> n >> k;
    bool x = true;
    if(k > (n-1)*(n-2)/2) {
        x = false;
    }
    vector<P> edge(n-1);
    rep(i, n-1) {
        edge[i] = P(n-1, i);
    }

    int ii = (n-1)*(n-2)/2-k;
    if(ii < 0) ii = 0;
    int i = 0;
    int j = 1;
    while(ii) {
        edge.push_back(P(i, j));
        if(j<n-2) {
            j++;
        } else {
            i++;
            j = i+1;
        }
        --ii;
    }
    if(!x) cout << -1 << endl;
    else {
        int m = edge.size();
        cout << m << endl;
        rep(i, m) {
            cout << edge[i].first+1 << ' ' << edge[i].second+1 << endl;
        }
    }
}