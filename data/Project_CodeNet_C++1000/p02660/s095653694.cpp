#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans=0;
int func(int n)
{
    for(int i=0; i<40; i++)
    {
        int sm=(i*(i+1))/2;
        if(sm>n)
        {
            return i-1;
        }
    }

}
void primeFactors(int n)
{
    int c=0;
    while (n%2 == 0)
    {
        c++;
        n = n/2;
    }
    ans+=func(c);
    c=0;
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
            c++;
            n = n/i;
        }
        ans+=func(c);
        c=0;
    }
    if (n > 2)
        ans++;
}
main()
{
    int n;
    cin>>n;
    primeFactors(n);
    cout<<ans<<endl;
    return 0;
}

