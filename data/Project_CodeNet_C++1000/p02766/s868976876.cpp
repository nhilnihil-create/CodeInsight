#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll INF=1e18;
    
int main(){
  int n,k;
  cin>>n>>k;
  bool judge=true;
  int l=1;
  int keta=1;
  while(judge){
    if(n/l==0){
      cout<<keta-1<<endl;
      judge=false;
      return 0;
    }else{
      l*=k;
      keta++;
      
    }
      
   
  }
  

}