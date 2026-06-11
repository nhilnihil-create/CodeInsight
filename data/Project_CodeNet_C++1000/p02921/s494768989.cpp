#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int cnt = 0; string S, T; cin >> S >> T;
    for (int i = 0; i < 3; ++i) if (S[i] == T[i]) cnt++;
    printf("%d\n", cnt);
}
