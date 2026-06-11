#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, a, b) for(int i = a, i##_len = (b); i < i##_len; ++i)

int main()
{
    int point[210];
    point[1] = 300000, point[2] = 200000, point[3] = 100000;
    for(int i = 4; i < 206; ++i) point[i] = 0;
    int X, Y;
    cin >> X >> Y;
    int res = point[X] + point[Y];
    if(X == 1 && Y == 1) res += 400000;
    cout << res << endl;
    return 0;
}