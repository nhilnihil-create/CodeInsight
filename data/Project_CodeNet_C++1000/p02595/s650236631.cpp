#include <bits/stdc++.h>
using namespace std;
long long int n,d;
int main()
{
    int dem=0;
    cin>>n>>d;
    while(n--)
    {
        long long int a,b;
        cin>>a>>b;
        if(sqrt(a*a + b*b) <= d) dem++;
    }
    cout<<dem;
}
