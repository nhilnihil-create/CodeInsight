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
    for(int i = 2; i < n; i++)
    {
        if(ar[i-1] < ar[i] && ar[i] < ar[i+1])
        {
            CountGood++;
        }
        else if(ar[i-1] > ar[i] && ar[i] > ar[i+1])
        {
            CountGood++;
        }
    }
    printf("%d\n", CountGood);
    return 0;
}
