#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;

int main(){
  int n;
  cin>>n;
  
  
  int m= (n+1)*100/108;
  bool judge=true;
  
  while(judge){
    if(m*108/100==n){
      cout<<m<<endl;
      judge=false;
      break;
    }
    
    if(m*108/100==n-1){
      cout<<":("<<endl;
      return 0;
    }
     m--; 
      
    
    
    
  }
  
  


}
