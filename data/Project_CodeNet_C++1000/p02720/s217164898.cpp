#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;

long ansiter = -1, ans = 0;

void solve(int depth, long pre, long k, long *flag, int flag0){
  if(depth==10){
    if(ansiter<k)ansiter++;
    if(ansiter==k){
      rep(i,10){
        ans += flag[9-i]*pow(10,i);
      }
    }
    return;
  }

  if(ansiter==k)return;
  if(flag0==0 && pre==0){
    rep(i,10){
      flag[depth] = i;
      if(ansiter<k && i==0)solve(depth+1,0,k,flag, flag0);
      else if(ansiter<k)solve(depth+1,i,k,flag, 1);
    }
  }else if(pre==0){
    flag0 = 1;
    flag[depth] = 0;
    if(ansiter<k)solve(depth+1,0,k,flag,flag0);
    flag[depth] = 1;
    if(ansiter<k)solve(depth+1,1,k,flag,flag0);
  }else if(pre==9){
    flag0 = 1;
    flag[depth] = 8;
    if(ansiter<k)solve(depth+1,8,k,flag,flag0);
    flag[depth] = 9;
    if(ansiter<k)solve(depth+1,9,k,flag,flag0);
  }else{
    flag0 = 1;
    flag[depth] = pre-1;
    if(ansiter<k)solve(depth+1,pre-1,k,flag,flag0);
    flag[depth] = pre;
    if(ansiter<k)solve(depth+1,pre,k,flag,flag0);
    flag[depth] = pre+1;
    if(ansiter<k)solve(depth+1,pre+1,k,flag,flag0);
  }
}

int main(){
  long k;
  cin >> k;
  long flag[10];
  solve(0,0,k,flag,0);
  cout << ans << endl;
  return 0;
}