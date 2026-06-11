#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int k = (a + b) / 2;

    if (abs(a-k) == abs(b-k)) cout << k;
    else cout << "IMPOSSIBLE";
}