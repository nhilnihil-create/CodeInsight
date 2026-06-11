#include<bits/stdc++.h>
using namespace std;
#define pi 3.14159265359
#define int long long
#define pii pair<int,int>
const int mod=1e9+7;

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};



int32_t  main()
{ 
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

    int ans=0;
   int m,d;
   cin>>m>>d;

   
   for(int i=1;i<=m;i++)
   {
     for(int j=2;j<=9;j++)
     {
       for(int k=2;k<=9;k++)
       {
         int x=j+k*10;
         if(x>d)break;
         if(j*k==i)ans++;    
       }
     }
   }
   cout<<ans<<"\n";

}

