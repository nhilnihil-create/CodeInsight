#include <bits/stdc++.h>
using namespace std;

int main()
{
        int n;
        scanf("%d",&n);
        int ans = 1;
        while (n * ans % 360) ++ans;
        printf("%d\n", ans);
}