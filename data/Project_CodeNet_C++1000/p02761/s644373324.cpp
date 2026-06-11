#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long a[5]={0,1,0,0,0},n,m,i,x,y,j,b[5]={0},f=0;
    cin>>n>>m;
    if(n==1&&m==0)
    {
        cout<<0<<endl;
    }
    else if(n>1&&m==0)
    {
        for(j=1;j<=n;j++)
        {
            cout<<a[j];
        }
        cout<<endl;
    }
    else
    {
        for(i=1;i<=m;i++)
        {
            cin>>x>>y;
            if(b[x]==0)
            {
                a[x]=y;
            }
            else
            {
                if(y!=a[x])
                {
                    f++;
                }
            }
            b[x]++;    
        }   
        if(f>0)
        {
            cout<<-1<<endl;
        }
        else if(a[1]==0&&n>1)
        {
            cout<<-1<<endl;
        }
        else
        {
            for(j=1;j<=n;j++)
            {
                cout<<a[j];
            }
            cout<<endl;
        }
    }   
    return 0;
}