#include<bits/stdc++.h>
using namespace std;
 typedef pair<long long,int> Pair; 
 const int maxn=2007;

 int N;
const int M=-1000000000000000;
 vector<Pair> A;
 long long f[maxn][maxn];

 long long dp(int x,int y)
 { 
   if(x==0&&y==0) return 0;
   if(f[x][y]!=M) return f[x][y];
   if(y==0) 
     f[x][y]=A[x+y-1].first*(A[x+y-1].second-x)+dp(x-1,y);
   if(x==0)
     f[x][y]=(-1)*A[x+y-1].first*(A[x+y-1].second-N-1+y)+dp(x,y-1);
   if(x>0&&y>0)
   {  f[x][y]=max(A[x+y-1].first*(A[x+y-1].second-x)+dp(x-1,y),(-1)*A[x+y-1].first*(A[x+y-1].second-N-1+y)+dp(x,y-1));
   }
   return f[x][y];
 }
     
   
 
int main()
{
  long long  i,j,k,ma;
  ma=0;
  cin>>N;
  
  for(i=0;i<N;i++)
  {
    cin >> k;
    A.push_back({k,i+1});
  }
  
   sort(A.begin(),A.end());
   reverse(A.begin(),A.end());
  
  for(i=0;i<maxn;i++)
  {
    for(j=0;j<maxn;j++)
    {
       f[i][j]=M;
    }
  }
  
  for(i=0;i<=N;i++)
  {
    ma=max(dp(i,N-i),ma);
  }
    
 /* for(i=0;i<=N;i++)
  {
    for(j=0;j<=N-i;j++)
    {
      cout << f[i][j] <<" "  ;
      if(i+j==N) cout << endl;
    }
  }*/
  cout << ma << endl;
    
  
  
  
  
  
}