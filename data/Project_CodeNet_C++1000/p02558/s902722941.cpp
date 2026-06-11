#include<bits/stdc++.h>
#include<atcoder/dsu> 

using namespace std;
using namespace atcoder;

int main(){
 
  int n;
  cin>>n;
  
  int q;
  cin>>q;
  dsu d(n);
  while(q--){
   
    int a,b,c;
    cin>>a>>b>>c;
    
    if(a==0){
      d.merge(b,c);
      
    }
    else{
     
      if(d.same(b,c)){
        cout<<1<<endl;
      }
      else cout<<0<<endl;
      
    }
    
  }
  
  
  
}