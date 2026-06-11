#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t,n,x;
    cin>>n>>x;
    t=n % x;
    cout<<min(t,x-t);
    return 0;
}

