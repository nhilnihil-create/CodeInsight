//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <deque>
#include <map>
using namespace std;

#define ii pair <int, int>
#define lli long long
#define pb push_back
#define X first
#define Y second

const int Mod = 1E9 + 7;
const int Inf = 1E9 + 7;
const int N = 2E5 + 10;

void Input()
{

}

void Solve()
{
    int x, y, z;
    cin >> x >> y >> z;
    if (x + y + z >= 22) cout << "bust";
    else cout << "win";
}

#define task "test"
int main()
{
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int testcase = 1;
    /// cin >> testcase;
    while (testcase--) {
        Input();
        Solve();
    }
}

