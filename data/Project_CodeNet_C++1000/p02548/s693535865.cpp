#include<bits/stdc++.h>
#define ll long long
#define un unsigned
using namespace std;
int main()
{
    ll n,cnt=0,i,j,k;
    cin>>n;
    k=(n/2)+1;
    //cnt=n-1;
    for(i=1;i<=n;i++)
    {
        for(j=1;i*j<n;j++)
        {
            if(i*j<n){
            cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
