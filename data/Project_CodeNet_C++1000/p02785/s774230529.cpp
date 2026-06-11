#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n,k,cnt=0,i;
    cin>>n>>k;
    lli a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    for(i=n-1;i>=0;i--)
    {
        if(k>0)
        {
            k--;
            a[i]=0;
        }
        else
        {
            cnt+=a[i];
        }
    }
    cout<<cnt<<"\n";
}