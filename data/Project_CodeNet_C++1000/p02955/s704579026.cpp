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
    scanf("%d %d", &n, &k);
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    auto F = factorize(accumulate(A.begin(), A.end(), 0));
    sort(F.begin(), F.end(), greater<int>());

    for (const auto &f: F){
        vector<int> B(n);
        // int border = 0;
        for (int i = 0; i < n; i++){
            B[i] = A[i] % f;
        }
        const auto S = accumulate(B.begin(), B.end(), 0);
        const auto i = S / f;
        nth_element(B.begin(), B.begin() + (n - i), B.end());
        if (max(accumulate(B.begin(), B.begin() + (n - i), 0), S - accumulate(B.begin() + (n - i), B.end(), 0)) <= k){
            printf("%d\n", f);
            return 0;
        }
    }

    puts("0");
}