#include<bits/stdc++.h>
using namespace std;
#define int  long long
#define tc(t)  int t; cin>>t; while(t--)
#define f(n)    for(int i=1;i<=n;i++)
#define endl   "\n"







int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b;
    cin>>a>>b;
    int count=0;
    for(int i=0;i<3;i++)
    {
        if(a[i]==b[i]) count++;
        
    }
    cout<<count<<endl;



}