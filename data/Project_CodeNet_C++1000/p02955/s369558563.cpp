#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector< int64_t > divisor(int64_t n) {
    vector< int64_t > ret;
    for(int64_t i = 1; i * i <= n; i++) {
        if(n % i == 0) {
        ret.push_back(i);
        if(i * i != n) ret.push_back(n / i);
        }
    }
    sort(rbegin(ret), rend(ret));
    return (ret);
}

int main(void) {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }

    auto d = divisor(accumulate(A.begin(), A.end(), 0));

    for(auto e: d) {
        vector<int> tmp(N);
        for(int i=0; i<N; i++) {
            tmp[i] = A[i] % e;
        }
        sort(tmp.begin(), tmp.end());
        for(int i=0; i<=N; i++) {
            int64_t sum1 = 0;
            int64_t sum2 = 0;
            for(int j=0; j<i; j++) {
                sum1 += tmp[j];
            }
            for(int j=i; j<N; j++) {
                sum2 += e-tmp[j];
            }
            if(sum1 == sum2 && sum1 <= K) {
                cout << e << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;
    return 0;
}
