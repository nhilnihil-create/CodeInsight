#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 998244353;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    vector<P>cnt(N);
    for(int i = 0; i < N; i++) {
        int X,L;
        cin >> X >> L;
        cnt[i].first = X+L;
        cnt[i].second = X-L;
    }
    sort(cnt.begin(),cnt.end());
    int ans = 0;
    int sum = -1000000000;
    for(int i = 0; i < N; i++) {
        if(cnt[i].second >= sum) {
            sum = cnt[i].first;
            ans++;
        }
    }
    cout << ans << endl;
}