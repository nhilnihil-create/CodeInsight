#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n ;
    cin>>n;

    int* b = new int[n]();
    for(int i=1;i<=n-1;i++)
    {
        cin>>b[i];
    }
    ll sum =0;
    int* a = new int[n+1]();
    a[1] = b[1];
    for(int i=2;i<=n-1;i++)
    {
        a[i] = min( b[i-1] , b[i] );
        sum += a[i];
    }
    sum += b[1];
    sum += b[n-1];
    cout<<sum;


}