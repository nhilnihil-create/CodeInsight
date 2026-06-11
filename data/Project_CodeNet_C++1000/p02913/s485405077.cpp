#include <bits/stdc++.h>

#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    using namespace std;
    const ll p = 1000000007,
             max_n = 5'000 + 1;
    array<ll, max_n> pp;
    pp[0] = 1;
    for(int i = 1; i < max_n; i++)
        pp[i] = pp[i - 1] * p;
    ll n;
    cin >> n;
    string S;
    cin >> S;

    vector<ll> A(n + 1, 0);
    for(int i = 0; i < n; i++)
        A[i + 1] = A[i] + S[i] * pp[i];

    int a = 0, b = n + 1, c;
    while(a < b) {
        c = (a + b + 1) / 2;
        bool found = false;
        for(int i = 0; i < n - 2 * c + 1; i++)
            for(int j = i + c; j < n - c + 1; j++)
                if((A[i + c] - A[i]) * pp[j - i] == A[j + c] - A[j]) {
                    found = true;
                    break;
                }
        if(found)
            a = c;
        else
            b = c - 1;
    }

    cout << a << "\n";
    
    return 0;
}
