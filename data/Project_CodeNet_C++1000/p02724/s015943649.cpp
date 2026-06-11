#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
////////////////////////////////////////////////
int main()
{
    int x;
    cin >> x;
    int pre = 0;
    pre += (x / 500) * 1000;
    x = x % 500;
    pre += (x / 5) * 5;
    cout << pre << endl;
}