#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W, N;
    cin >> H >> W >> N;
    auto vmax = max(H, W);
    cout << ((N + vmax - 1) / vmax) << endl;
    return 0;
}