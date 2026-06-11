#include <bits/stdc++.h>
using namespace std;

int64_t caracalBattle(int64_t h) {
    if (h == 1) return 1;

    return caracalBattle(h / 2) * 2 + 1;
}

int main() {
    int64_t H; cin >> H;
    cout << caracalBattle(H) << endl;
}