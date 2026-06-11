#include<bits/stdc++.h>
using namespace std;
int i,j,n,x,mx=0,a;
map<int,int>m;
int main()
{
    cin>>n;
    for(j=1;j<=n;j++)
    {cin>>x;
       for(i=2;i*i<=x;i++)
       {
        a=0;
        while(x%i==0)
          {x/=i;
          if(!a){
             m[i]++;a++;}
           mx=max(m[i],mx);
          }
       }
       if(x!=1){m[x]++;mx=max(m[x],mx);}
    }
    if(mx==1||mx==0)cout<<"pairwise coprime";
    else if(mx<n)cout<<"setwise coprime";
    else cout<<"not coprime";
}