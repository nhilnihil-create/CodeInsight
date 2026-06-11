#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<bitset>
#include<utility>
#include<string>

using namespace std;

int n;
int in[105];
unsigned long long int pm(int now,int sum);
unsigned long long int memo[105][30];

main(){
  memset(memo,-1,sizeof(memo));

  cin >> n;
  for(int i=0;i<n;i++) cin >> in[i];
  cout << pm(0,0) << endl;

}

unsigned long long int pm(int now,int sum){
  if(now==n-1){
    if(sum==in[now]) return 1;
    else return 0;
  }

  if(memo[now][sum]!=-1) return memo[now][sum];

  if(now==0 && in[now]==0) return memo[now][sum]=pm(now+1,sum);

  if(sum+in[now]<=20){
    if(0<=sum-in[now]){
      return memo[now][sum]=pm(now+1,sum+in[now])+pm(now+1,sum-in[now]);
    }
    else return memo[now][sum]=pm(now+1,sum+in[now]);
  }
  else if(0<=sum-in[now]){
    return memo[now][sum]=pm(now+1,sum-in[now]);
  }

  return memo[now][sum]=0;

}