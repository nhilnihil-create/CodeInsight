#include<iostream>
#include<cmath>
#include<numeric>
#include<functional>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<n;i++)
#define ll long long
#define INF 2147483647
using namespace std;
using Graph=vector<vector<int>>;

int main(){
  ll mod=1000000007;
  ll s; cin>>s;
  ll ans[2001]; ans[1]=0; ans[2]=0;
  for(int i=3;i<=2000;i++){
    ans[i]=1;
    for(int j=3;j<=i-3;j++){
      ans[i]+=ans[j];
      ans[i]%=mod;
    }
  }
  cout<<ans[s];
}
