#include <bits/stdc++.h>
using namespace std;

template<class INT>
std::vector<INT> factorize(INT n){
    std::vector<INT> res;
    for (INT i = 1; i * i <= n; i++){
        if (n % i == 0){
            res.push_back(i);
            if (i * i != n)
                res.push_back(n / i);
        }
    }
    return res;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int64_t> A(n);
    copy_n(istream_iterator<int64_t>(cin), n, A.begin());
    auto s = accumulate(A.begin(), A.end(), 0L);
    auto factors = factorize(s);

    int64_t ans = 0;
    for (const auto &f: factors){
        vector<int64_t> B(n);
        for (int i = 0; i < n; i++)
            B[i] = A[i] % f;
        sort(B.begin(), B.end());
        vector<int64_t> acc(n + 1);
        for (int i = 0; i < n; i++)
            acc[i + 1] = acc[i] + B[i];
        for (int i = 0; i < n; i++){
            if (max(acc[i], f * (n - i) - (acc[n] - acc[i])) <= k)
                ans = max(ans, f);
        }
    }

    cout << ans << endl;

}