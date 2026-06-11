#include <bits/stdc++.h>
using namespace std;

int main(void) {
    char S[4] = {0};
    char T[4] = {0};
    char *p;
    uint32_t a;
    cin >> S >> T;
    a = (*((uint32_t*)S)) ^ (*((uint32_t*)T));
    p = (char*)&a;
    cout << 3- (p[0]!=0) - (p[1]!=0) - (p[2]!=0) << "\n";
    return 0;
}
