#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define MOD 1000000007
#define el endl
#define INF 1e8
typedef long long ll;
typedef long double ld;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> c(n);
    rep(i, n) cin >> c[i].first >> c[i].second;
    int mmax = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i==j) continue;
            int p = c[i].first - c[j].first;
            int q = c[i].second - c[j].second;
            for(int k = 0; k < n; k++){
                for(int l = 0; l < n; l++){
                    if(k==l)continue;
                    if(c[k].first - c[l].first == p
                       && (c[k].second - c[l].second) == q) {
                        cnt++;
                    }
                }
            }
            mmax = max(mmax, cnt);
            cnt = 0;
        }
    }
    cout << n - mmax << endl;
}

