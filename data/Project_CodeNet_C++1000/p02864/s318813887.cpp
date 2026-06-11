#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int cc[305];
int dp[305][305][305];
int pre[305][305];
int suf[305][305];
signed main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);  
     cout.tie(0);   
 #ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
    freopen ("INPUT.txt" , "r" , stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
    }
 #endif
 
// -------------------------------------Code starts here---------------------------------------------------------------------     

   fill_n(&dp[0][0][0],305*305*305,1e17);
   dp[0][0][0]=0;
   int n,k;
   cin>>n>>k;
   int h[n+1];
   for(int i=1;i<=n;i++)
   {
      cin>>h[i];
      cc[i]=h[i];
   }

   sort(cc+1,cc+n+1);
   cc[n+1]=1e17;
   fill_n(&pre[0][0],305*305,1e17);
   fill_n(&suf[0][0],305*305,1e17);
   pre[0][0]=cc[n];
   for(int j=1;j<=n;j++)
   {
      pre[j][0]=cc[n];
   }
   suf[0][0]=0;
   for(int i=1;i<=n;i++)
   {
      for(int j=0;j<=n;j++)
      {
         for(int l=0;l<=k;l++)
         {
            if(cc[j]==h[i])
            {
               dp[i][j][l]=min(suf[j][l],pre[j][l]-(cc[n]-cc[j]));
            }
            else
            {
               if(l>0)
                  dp[i][j][l]=min(suf[j][l-1],pre[j][l-1]-(cc[n]-cc[j]));
            }
         }
      }
      fill_n(&pre[0][0],305*305,1e17);
      fill_n(&suf[0][0],305*305,1e17);
      for(int l=0;l<=k;l++)
      {
         for(int j=0;j<=n;j++)
         {
            if(j==0)
               pre[j][l]=dp[i][j][l]+cc[n];
            else
               pre[j][l]=min(dp[i][j][l]+cc[n]-cc[j],pre[j-1][l]);  
         }
      }
      for(int l=0;l<=k;l++)
      {
         for(int j=n;j>=0;j--)
         {
            suf[j][l]=min(dp[i][j][l],suf[j+1][l]);
         }
      }
   }

   int mn=1e17;
   for(int i=0;i<=n;i++)
      for(int j=0;j<=k;j++)
         mn=min(mn,dp[n][i][j]);
   cout<<mn;


// -------------------------------------Code ends here------------------------------------------------------------------
     clock_t clk;
 	clk = clock();
 
    clk = clock() - clk;
 	cerr << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
 	return 0;
 }
 