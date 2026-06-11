#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

int digit(int n){
  int left;
  while(n>0){
    left=n%10;
    n/=10;
  }
  return left;
}

int n;
vector<int> vec(100);

void dfs(int left,int now,int d=1){
  if(now<=n) {vec[left*10+now%10]++;}
  if(d==6) return;
  for(int i=0; i <=9; i++){
    dfs(left,now*10+i,d+1);
  }
}

int main(){
  cin>>n;
  rep(i,100) vec[i]=0;
  for(int left=1; left<=9; left++){
    dfs(left,left);
  }
  int ans=0;
  for(int a=1; a<=n; a++){
    if(a%10==0) continue;
    int left=digit(a),right=a%10;
    ans+=vec[right*10+left];
  }
  cout<<ans<<endl;
}

