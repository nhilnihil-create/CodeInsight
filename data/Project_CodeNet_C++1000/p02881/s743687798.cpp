#include<bits/stdc++.h>
using namespace std;
#define int  long long
#define tc(t)  int t; cin>>t; while(t--)
#define f(n)    for(int i=0;i<n;i++)
#define endl   "\n"
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    if(n==1) {
        cout<<"0"<<endl;
        return 0;
    }
    if(n==2)
    {
        cout<<"1"<<endl;
        return 0;
    }
    int a=1;
    int b=1;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            a=i;
            b=n/i;
        }


    }
    if(a==1&&b==1)
    {
        a=n;
        b=1;
    }
    //cout<<a<<" "<<b<<endl;
    cout<<(a+b-2)<<endl;


}