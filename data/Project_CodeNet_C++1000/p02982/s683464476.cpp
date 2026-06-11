#include<bits/stdc++.h>
#define ll long long 
#define ld long double
#define pb push_back
#define vl vector
#define ff first
#define ss second
using namespace std;
int main()
{
    ll a,b,i,j,n,t,d,k;
    cin>>n>>d;
    ll arr[n][d];
    for(i=0;i<n;i++) for(j=0;j<d;j++) cin>>arr[i][j];
    ll count=0;
    for(i=0;i<n;i++) for(j=0;j<n;j++)
    {
        ll sum=0;
        if(i!=j)
        {
            for(k=0;k<d;k++) 
            {
                b=abs(arr[i][k]-arr[j][k]);
                b*=b;
                sum+=b;
            }
            ld ss=sum;
            sum=sqrt(sum);
            ss=sqrt(ss);
            ss=ceil(ss);
            a=(ll)ss;
            if(a==sum) count++;
        }
    }
    count/=2;
    cout<<count;
}