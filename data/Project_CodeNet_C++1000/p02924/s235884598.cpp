#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin>>n;
    if(n==0)
    {
        cout<<0;
        return 0;
    }
    n--;
    cout<<(n*(n+1))/2;
    return 0;
}

