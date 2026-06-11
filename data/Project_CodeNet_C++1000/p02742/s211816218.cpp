#include<iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    uint32_t H, W;   
    cin >> H >> W;

    if (H == 1 || W == 1)
        cout << 1 << endl;
    else
        cout << W * (uint64_t)(H / 2) + (H % 2) * ((uint64_t)((W + 1) / 2)) << endl;

    return 0;
}