#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  int n,m;
  cin >> n >> m;
  if(n & 1){
    for(int i = 1,j = n;i <= m;i++,j--)printf("%d %d\n",i,j);
  }else{
    bool is = false;
    for(int i = 1,j = n-1;m;i++,j--){
      if(!is && j-i <= n/2){
        j--;
        is = true;
      }
      printf("%d %d\n",i,j);
      m--;
    }
  }
  
  
  
  return 0;
}