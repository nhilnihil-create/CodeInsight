#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
typedef pair<int,int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000000000

int MOD=1000000007;
int modpow(int a,int x){
  if(a<0)a+=MOD;
  int ans=1;
  while(x>0){
    if(x&1) ans=ans*a%MOD;
      a=a*a%MOD;
      x>>=1;
  }
  return ans;
}

int gyaku(int n){
    return modpow(n,MOD-2);
}

signed main() {
  int k;
  cin>>k;
vector<int>run={1,2,3,4,5,6,7,8,9};
int x=0;
while(x<=100001){
  int t=run.at(x);
  if(t%10==0){
      run.push_back(t*10);
      run.push_back(t*10+1);
  }
  else if(t%10==9){
    run.push_back(t*10+8);
    run.push_back(t*10+9);
  }
  else{
    int t2=t%10;
    run.push_back(t*10+t2-1);
    run.push_back(t*10+t2);
    run.push_back(t*10+t2+1);
  }
  x++;
}
cout<<run.at(k-1)<<endl;
}
