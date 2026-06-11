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
    } else {
        cout << (num+1)/2 << endl;
    }
    return 0;
}
