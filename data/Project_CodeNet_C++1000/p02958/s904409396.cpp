#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; scanf("%d", &n);
    int ar[n+5] = {};
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &ar[i]);
    }
    int CountGood = 0;
    for(int i = 1; i <= n; i++)
    {
        if(ar[i] != i)
        {
            CountGood++;
        }
    }
    if(CountGood <= 2)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}
