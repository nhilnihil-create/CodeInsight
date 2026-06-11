#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    ull a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    ull prod=1;
    sort(a,a+n);
    if(a[0]==0)
    {
        cout<<0;
    }
    else
    {
        bool flag=0;
        for(int i=0;i<n;i++)
        {
            if(prod<=1000000000000000000/a[i])
            {
                prod*=a[i];
            }
            else
            {
                flag=1;
                break;
            }
        }
        if(flag)
        {
            cout<<-1;
        }
        else cout<<prod;
    }
    return 0;
}