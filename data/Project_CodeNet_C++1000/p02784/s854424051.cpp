#include<bits/stdc++.h>
using namespace std;
#define mx 1000000000000000000
#define ll long long int
//ll number[20],used[20];
int main()
{
    ll n,i,a[100000],count,sum=0;
    cin>> n >> count ;
    for(i=0;i<count;i++)
    {
        cin>> a[i];
        sum+=a[i];
    }
    if(sum>=n)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
