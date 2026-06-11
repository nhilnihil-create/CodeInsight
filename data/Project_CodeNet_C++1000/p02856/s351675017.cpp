#include<bits/stdc++.h>
using namespace std;

int main() {
    int M; cin >> M;
    long long ans = 0, digit = 0;
    for (int i = 0; i < M; i++)
    {
        long long d, c; cin >> d >> c;
        ans += d * c;
        digit += c;
    }

    cout << digit - 1 + ((ans - 1) / 9) << endl;
}