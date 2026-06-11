#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include<iomanip>
#define endl "\n"
#define ll long long
#define countBit1(x) __builtin_popcountll(x)
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int l, r , x;
    cin >> l >> r >> x;
    int res= 0;
    for(int i = l; i <= r; i++)
    {
        i % x == 0 ? ++res : 0;
    }
    cout << res;
    return 0;
}