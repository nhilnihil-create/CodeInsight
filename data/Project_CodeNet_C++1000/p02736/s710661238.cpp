#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    string S;
    cin >> S;
    for (int i = 0; i < n; i++)
        A[i] =  S[i] - '0';
    for (int i = 0; i < n - 1; i++)
        A[i] = abs(A[i] - A[i + 1]);
    n--;
    A.erase(A.begin() + n, A.end());

    auto f = [&](){
        int b = 0;
        for (int i = 0; i < n; i++){
            b ^= (A[i] & 1) & (((n - 1) & i) == i);
        }
        return b;
    };

    if (f() == 1){
        puts("1");
        return 0;
    }

    if (any_of(A.begin(), A.end(), [](const auto &a){return a == 1;})){
        puts("0");
        return 0;
    }

    for (auto &a: A)
        a >>= 1;

    puts(f() == 1 ? "2" : "0");
}
