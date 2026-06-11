#include<bits/stdc++.h>
using namespace std;
int main()
{
   int x=0 ,y=0,m,n,i,j,k;
   cin >> n >> m;
   string s;
   map<int,int>mp,mp1;
   for(i = 0 ;i<m ;i++)
   {
       cin >> k >>s;
       if(s == "AC" && mp1[k]==0)
        {
            x++;y+=mp[k];
            mp1[k]=1;
        }
       else
        mp[k]++;
   }
   cout<<x<<" "<<y<<endl;
}


