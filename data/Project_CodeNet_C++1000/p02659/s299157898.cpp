#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int64_t a;
    int bl, br;
    char dot;
    cin >> a >> bl >> dot >> br;
    cout << (int64_t) a * (bl * 100 + br) / 100 << "\n";
}
