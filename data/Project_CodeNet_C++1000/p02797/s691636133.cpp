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
  int n,k,s; cin>>n>>k>>s;
  int ans[n];
  if(1){
    rep(i,n){
      if(1000000000%s!=0){
        ans[i]=1000000000;
      }else{
        ans[i]=999999999;
      }
    }
    rep(i,k){
      ans[i]=s;
    }
    rep(i,n){
      cout<<ans[i]<<" ";
    }
  }
}
