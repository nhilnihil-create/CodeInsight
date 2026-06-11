#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9+7;
typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<lli> vlli;
typedef vector<bool> vb;
long long int max(long long int a,long long int b){
  if(a>b)
    return a;
  else
    return b;
}
long long int min(long long int a,long long int b){
  if(a<b)
    return a;
  else
    return b;
}
long long int binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a % m;
      a = a * a % m;
      b >>= 1;
    }
  return res;
}
long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}
 
//############################ENDOFTEMPLATE############################

int dfs(lli num,lli x,int dig){
  if(num>x) return 0;

  lli cpy = num;
  int d = 0;

  while(cpy>0){
    d++;
    cpy/=10;
  }
  if(d==dig){
    return 1;
  }

  int ld = num%10;

  lli curr = 0;
  for(int i = -1;i<=1;i++){
    if(ld+i>=0 && ld+i<=9)
      curr = curr+dfs(num*10+ld+i,x,dig);
  }

  return curr;

}



bool check(lli x,int k,vi& less){
  //cout<<x<<endl;
  int dig = 0;
  lli cx = x;
  while(cx>0){
    dig++;
    cx/=10;
  }

  if(less[dig-1]>k)
    return false;

  lli val = less[dig-1];

  cx = x;
  while(cx>=10){
    cx/=10;
  }

  for(int i = 1;i<=cx;i++){
    val = val+dfs(i,x,dig);
  }

  

  if(val<k)
    return true;

  return false;

}

void solve(){
  int k;
  cin>>k;

  vector<vi> dp(13,vi(10,0));
  for(int i = 1;i<=9;i++){
    dp[1][i] = 1;
  }

  for(int i = 2;i<=12;i++){
    for(int j = 0;j<=9;j++){
      dp[i][j] = dp[i-1][j]+(j+1<10?dp[i-1][j+1]:0)+ (j-1>=0?dp[i-1][j-1]:0);
    }
  }

  vi less(13,0);

  for(int i = 0;i<=12;i++){
    for(int j = 0;j<=9;j++){
      less[i]+=dp[i][j];
    }
  }

  for(int i = 1;i<=12;i++){
    less[i] = less[i-1]+less[i];
    //cout<<less[i]<<" ";
  }

  //cout<<endl;

  lli x = 0;

  for(lli b = 3234566667+1;b>=1;b/=2){
    while(check(x+b,k,less)) x+=b;
  }


  ///for(int i = 1;i<=9;i++){
    //cout<<dfs(i,i,1)<<endl;
  //}

  cout<<x+1;

}

 
 
 
 
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  //freopen("moobuzz.in","r",stdin);
  //freopen("moobuzz.out","w",stdout);
  int t = 1;
  //cin>>t;
  while(t--){
    solve();
  }
}