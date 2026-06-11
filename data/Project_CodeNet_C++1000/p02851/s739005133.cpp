#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(void) {
    int64_t N, K;
    cin >> N >> K;
    vector<int64_t> A(N+1);
    for(int i=1; i<=N; i++) {
        cin >> A[i];
    }

    for(int i=1; i<=N; i++) {
        A[i] = (A[i-1] + A[i] - 1) % K;
    }

    map<int64_t,int64_t> mp;
    for(int i=0; i<min(N+1, K); i++) {
        mp[A[i]]++;
    }

    int64_t ans = 0;
    for(int i=0; i<N; i++) {
        mp[A[i]]--;
        ans += mp[A[i]];
        if(i+K <= N) mp[A[i+K]]++;
    }

    cout << ans << endl;
    return 0;
}
