//Radhe Radhe
#include<bits/stdc++.h>//157B
#define ll long long
#define fixed cout.setf(ios::fixed);
#define rep1    for( i=0; i<n; i++)
#define Precise cout.precision(7);
using namespace std;

int main()
{
    ll n,a[3][3],i,j;
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            cin>>a[i][j];
    ll x;
    cin>>n;
    while(n--)
    {
        cin>>x;
        for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
            {
                if(a[i][j]==x){
                    a[i][j]=1;
                    //break;
                }
            }
        }
    }
    if(a[0][0]==1&&a[1][1]==1&&a[2][2]==1)
       return cout<<"Yes"<<endl,0;
    else if(a[0][2]==1&&a[1][1]==1&&a[2][0]==1)
       return cout<<"Yes"<<endl,0;
        for(i=0; i<3; i++)
     if(a[i][0]==1&&a[i][1]==1&&a[i][2]==1)
       return cout<<"Yes"<<endl,0;
        for(i=0; i<3; i++)
     if(a[0][i]==1&&a[1][i]==1&&a[2][i]==1)
       return cout<<"Yes"<<endl,0;


       return cout<<"No"<<endl,0;

    return 0;
}



