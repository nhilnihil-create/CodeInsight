#include <bits/stdc++.h>
using namespace std;

double n, h, w;

int main() {
    cin >> h >> w >> n;
    cout << ceil(n / max(h, w));
}