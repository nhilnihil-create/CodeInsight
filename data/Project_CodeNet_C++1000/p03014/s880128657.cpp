#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007


int main()
{
   int n,m;
   cin>>n>>m;
   string str[n];
   for(int i=0;i<n;i++)
      cin>>str[i];

   int left[n][m]{};
   int right[n][m]{};
   int up[n][m]{};
   int down[n][m]{};

   for(int i=0;i<n;i++)
   {
      int count = 0;
      for(int j=0;j<m;j++)
      {
         if(str[i][j] == '.')
         {
            count++;
            left[i][j] = count;
         }
         else
            count = 0;
      }
   }
   for(int i=0;i<n;i++)
   {
      int count = 0;
      for(int j=m-1;j>=0;j--)
      {
         if(str[i][j] == '.')
         {
            count++;
            right[i][j] = count;
         }
         else
            count = 0;
      }
   }

   for(int i=0;i<m;i++)
   {
      int count = 0;
      for(int j=0;j<n;j++)
      {
         if(str[j][i] == '.')
         {
            count++;
            down[j][i] = count;
         }
         else
            count = 0;
      }
   }

   for(int i=0;i<m;i++)
   {
      int count = 0;
      for(int j=n-1;j>=0;j--)
      {
         if(str[j][i] == '.')
         {
            count++;
            up[j][i] = count;
         }
         else
            count = 0;
      }
   }

   int ans{};
   for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
         if(str[i][j] == '.')
            ans = max(ans,left[i][j] + right[i][j] + up[i][j] + down[i][j] - 3);
   
   cout<<ans;
   return 0;
}
