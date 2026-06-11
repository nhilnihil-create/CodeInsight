#include<bits/stdc++.h>
using namespace std;
int main()
{

    long long int n,d;
    cin>>n>>d;
    long long int ans=0;
    for(int i=1;i<=n;i++)
    {

        long long int x,y;
        cin>>x>>y;
        if(1LL*x*x+1LL*y*y<=1LL*d*d)
            ans++;
    }
    cout<<ans<<endl;
}
