#include<bits/stdc++.h>
using namespace std;
#define nl '\n'
int main()
{
    int n,sum=0,k,a;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
       cin>>a;
       if(a>=k)
         sum++;
    }
    cout<<sum;
    nl;
    return 0;
}
