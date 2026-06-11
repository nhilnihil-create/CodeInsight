#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,D,A;
    cin >> N >> D >> A;
    vector<P>cnt(N);
    for(int i = 0; i < N; i++) {
        cin >> cnt[i].first >> cnt[i].second;
    }
    sort(cnt.begin(),cnt.end());
    vector<int>sum(N+2);
    int ans = 0;
    for(int i = 0; i < N; i++) {
        sum[i+1]+=sum[i];
        cnt[i].second-=sum[i+1];
        if(cnt[i].second <= 0) {
            continue;
        }
        ans += (cnt[i].second+A-1)/A;
        sum[i+1] += (cnt[i].second+A-1)/A*A;
        sum[upper_bound(cnt.begin(),cnt.end(),make_pair(cnt[i].first+D*2,INF))-cnt.begin()+1]-=(cnt[i].second+A-1)/A*A;
    }
    cout << ans << endl;
}