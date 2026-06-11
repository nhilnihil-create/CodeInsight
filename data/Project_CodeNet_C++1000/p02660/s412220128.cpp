#include <iostream>
#include <vector>
using namespace std;

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
     // cout << ex << endl;

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}

int main() {
    long long N;
    cin >> N;
    const auto &res = prime_factorize(N);
    long long ans = 0;
    for (auto p : res) {
        for (int i = 1; i < N+1; ++i){
          p.second -= i;
          //cout << p.second << endl;
          if(p.second < 0) break; 
          ans++;
        }
    }
    cout << ans << endl;
}