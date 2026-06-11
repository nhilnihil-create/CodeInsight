//#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#define N 100099
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define LL long long
using namespace std;
int n;
struct DOT
{
    int v, id;
    bool operator<(const DOT y) const
    {
        return v < y.v;
    }
} p[N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i].v);
        p[i].id = i;
    }
    sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n; i++)
        printf("%d ", p[i].id);
    cout << endl;
    return 0;
}
