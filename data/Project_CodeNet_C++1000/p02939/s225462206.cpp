#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
vector<vector<int>> graph;

bool sort_sec(const pair<int,int> &a,const pair<int,int> &b){
   if(a.second<b.second){
      return true;
   }
   return false;
}

void swap(int *a,int *b){
   int temp=*a;
   *a=*b;
   *b=temp;
}

int gcd(int a,int b){
   if(a%b==0) return b;
   return gcd(b,a%b);
}
int digit(long long num){
   int cnt=0;
   while(num!=0){
      cnt+=num%10;
      num=num/10;
   }
   return cnt;
}
int main(void){
   string S;
   cin>>S;
   int N=S.size();
   vector<vector<int>> dp(N+1,vector<int>(3,-1));
   dp[0][0]=0;
   for(int i=0;i<N;i++){
      for(int j=0;j<=2;j++){
         if(dp[i][j]==-1) continue;
         for(int k=1;k<=2&&i+k<=N;k++){
            if(j!=k||S.substr(i-j,j)!=S.substr(i,k)){
               dp[i+k][k]=max(dp[i+k][k],dp[i][j]+1);
            }
         }
      }
   }
   int ans=0;
   for(int i=0;i<=2;i++){
      ans=max(ans,dp[N][i]);
   }
   cout<<ans<<endl;
   return 0;
}
