#include <bits/stdc++.h>

using namespace std;
int main()
{
    long long int p=100,n,c=0,i;
    cin>>n;
    while(p<n)
    {
        p=p+p/100;
        c++;
    }
    cout<<c;




   return 0;
}
