#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;

int main(){
  int n,k,c;
  string s;
  cin >>n>>k>>c;
  cin >>s;

  vector<int> l(k,0),r(k,n); //i番目の仕事日はl(i)日以降,r(i)日以前．
  
  int il=0,ir=k-1;
  int yl=-1, yr=-1;
  rep(i,n){ 

    
    if(s[i]=='o' && il<=k-1 && yl<0){
      
      l[il]=i;
      il++;
      yl=c;
    }
    
    
    if(s[n-1-i]=='o' && ir>=0 && yr<0){
      r[ir]=n-1-i;
      ir--;
      yr=c;
    }
    
    yl--;
    yr--;
  }
  
  rep(i,k){
   // cout<<r[i]<<" "<<l[i]<<" "<<endl;;
    if(r[i]==l[i]){
      cout<<r[i]+1<<endl;
    }
  }
  return 0;
  
}
