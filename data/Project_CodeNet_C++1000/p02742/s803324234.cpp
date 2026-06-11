#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    long long H, W;
    long long num;
    cin >> H >> W;
    num = H*W;
    if (H == 1 || W == 1) {
        cout << 1 << endl;
    } else if (num % 2 != 0) {
        cout << num / 2 + 1 << endl;
    } else {
        cout << num / 2 << endl;
    }
    return 0;
}
