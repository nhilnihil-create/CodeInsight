#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
using ll = long long;
const ll MOD = 1000000007;//998244353;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int N, K; cin >> N >> K;
   vector<int> A(N);
   rep(i,N)cin>>A[i];
   map<int,int> cnt;
   ll sum = 0;
   ll ans = 0;
   cnt[0]++;
   queue<pair<int, int>> que;
   que.push({K-1,0});
   rep(i,N){
        if (que.front().first == i){
            cnt[que.front().second]--;
            que.pop();
        }
        sum += A[i]-1;
        sum %= K;
        ans += cnt[sum];
        cnt[sum]++;
        que.push({i+K,sum});
   }
   cout << ans << endl;
}