#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
//#define int long long
template<class T> inline bool chmax(T& a,T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a,T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int N, K, left = 0;
    cin >> N >> K;
    long long ans = 0;
    vector<long long> A(N), sum(N+1, 0);
    map<long long, long long> mp;
    for (int i = 0; i < N; i++) {
        cin >> A[i]; A[i]--;
        sum[i+1] = (sum[i] + A[i]) % K;
    }
    
    auto add = [&](int i)->long long {
        if (mp.count(sum[i])) { mp[sum[i]]++; }
        else { mp[sum[i]] = 1; }
        return mp[sum[i]] - 1;
    };
    auto erase = [&](int i) { if (mp.count(sum[i])) --mp[sum[i]]; return; };
    
    for (int right = 0; right <= N;) {
        while (left <= N && abs(right-left) < K) ans += add(left++);
        erase(right++);
    }
    cout << ans << endl;
    return 0;
}