#include<bits/stdc++.h>
#define FastRead                      \
                                    ios_base::sync_with_stdio(false); \
                                    cin.tie(0);
#define ll long long
#define endl "\n"
#define f for
#define pi acos(-1)
using namespace std;
int main()

{
    FastRead
    ll int t,j,i,n;
    //cin>>t;
    //f(j=0;j<t;j++)
    //{
    cin>>n;
    ll int a[n],c=0,mn;
    f(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    f(i=0; i<n; i++)
    {
        if(i==0)
            mn=a[i];
        else
        {
            if(a[i]<mn)
            {
                c++;
                mn=a[i];
            }
        }

    }
    cout<<c+1<<endl;;

    //}
    return 0;
}