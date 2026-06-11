#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,lleg=0,rleg=0,bef=-1,ans=0;
    
    while(1)
    {
        //input
        cin>>n;
        if(n==0)
        {
            break;
        }
      
        string f[n]={};
        for(i=0;i<n;i++)
        {
            cin>>f[i];
        }

        for(i=0;i<n;i++)
        {
            if(f[i].compare("lu")==0)
            {
                lleg=1;
            }
            else if(f[i].compare("ru")==0)
            {
                rleg=1;
            }
            else if(f[i].compare("ld")==0)
            {
                lleg=-1;
            }
            else if(f[i].compare("rd")==0)
            {
                rleg=-1;
            }

            if(lleg==rleg&&lleg==1&&bef==-1)
            {
                ans++;
                bef=1;
            }
            else if(lleg==rleg&&lleg==-1&&bef==1)
            {
                ans++;
                bef=-1;
            }
        }
        cout<<ans<<endl;
      	lleg=0,rleg=0,bef=-1,ans=0;
    }
}
