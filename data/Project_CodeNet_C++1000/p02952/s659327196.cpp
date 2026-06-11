#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n; scanf("%lld", &n);
    int Count = 0;
    for(int i = 1; i <= n; i++)
    {
        int p = i;
        int Coun = 0;
        while(p)
        {
            Coun++;
            p /= 10;
        }
        if(Coun%2 == 1)
        {
            Count++;
        }
    }
    cout << Count << endl;
    return 0;
}
