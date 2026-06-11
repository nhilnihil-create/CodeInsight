#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    long long s;
    cin >> s;
    int x1, y1, x2, y2, x3, y3;
    x1 = y1 = 0;
    int v = 1e9;
    x2 = 1e9;
    y2 = 1;
    x3 = (v - s % v) % v;
    y3 = (s + x3) / v;
    printf("%d %d %d %d %d %d\n", x1, y1, x2, y2, x3, y3);
    return 0;
}