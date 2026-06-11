#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<int> cnt(N+1);
    for (int i = 0; i < N; i++) {
        cnt[A[i]]++;
    }

    long long sum = 0;
    for (int i = 1; i <= N; i++) {
        long long n = cnt[i];
        sum += n * (n-1) / 2;
    }
    
    for (int i = 0; i < N; i++) {
        long long ans = sum - cnt[A[i]] + 1;
        cout << ans << endl;
    }
}