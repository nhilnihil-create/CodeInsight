#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    double cnt=0,ans;
    for(int i=1;i<=n;i++)
    {
        if(i%2==1)
        {
            cnt++;
        }
    }

    ans=cnt/n;
    cout<<ans<<endl;
    exit(0);
}
