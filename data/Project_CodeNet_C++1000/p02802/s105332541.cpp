#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
    int n , k , ga;
    cin>>n>>k;
    if(k==0)
    {
        cout<<"0 0";
    } else {
        int ca[n+1] = { 0 };
        int wa[n+1] = { 0 };
        int x;
        string s,c="AC";
        while(k--)
        {
            cin>>x>>s;
            if(s==c)
            {
                ca[x]=1;
            } else {
                if(ca[x]==0)
                {
                    wa[x]++;
                }
            }
        }
        
        int ans1 = 0 , ans2 = 0;
        for(int i = 1;i<=n;i++)
        {
          ans1 = ans1+ca[i];
          if(ca[i]==1)
          ans2 = ans2 +wa[i];
        }
        
        cout<<ans1<<" "<<ans2;
    }
    return 0;
}