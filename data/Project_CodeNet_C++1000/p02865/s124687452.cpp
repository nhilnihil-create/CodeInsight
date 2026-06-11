#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    int limit = n / 2, ans = 0;
    for (int i = 1; i <= limit; i++) {
        if(i != n - i)
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}