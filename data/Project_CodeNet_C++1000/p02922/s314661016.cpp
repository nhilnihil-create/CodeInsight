#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int A, B, A1;
    cin >> A >> B;
    A1 = 1;
    int cnt = 0;
    while (A1 < B) {
        A1 += (A - 1);
        cnt ++;
    }
    cout << cnt << endl;
}