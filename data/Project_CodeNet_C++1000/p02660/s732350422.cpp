#include <bits/stdc++.h>

using namespace std;

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long>> res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}

int main() {
    long n;
    cin >> n;

    int count = 0;

    auto P = prime_factorize(n);

    for(auto i:P){
        int ex=1;
        while(true){
            if(i.second-ex>=0){
                i.second-=ex;
                ex++;
                count++;
            }else{
                break;
            }
        }
    }
    cout << count << endl;
}