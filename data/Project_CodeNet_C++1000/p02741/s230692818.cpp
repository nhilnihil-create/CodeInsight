#include <bits/stdc++.h>
using namespace std;
const int u[100] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};

int main()
{
    int k;
    scanf("%d", &k);
    printf("%d\n", u[k - 1]);
    return 0;
}
