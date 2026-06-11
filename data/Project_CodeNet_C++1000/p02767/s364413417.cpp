#include<bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    cin>>n;
    vector<int> x(n);
    //int p=1;
    for(int i=0;i<n;i++)
       cin>>x[i];

    int ans=(int)1e9;
    for(int i=1;i<=100;i++)
    {
        int cost=0;
        for(int j=0;j<n;j++)
        {
            cost+=(x[j]-i)*(x[j]-i);
        }
            ans=min(ans,cost);
    }
cout<<ans<<"\n";
   return 0;
}
