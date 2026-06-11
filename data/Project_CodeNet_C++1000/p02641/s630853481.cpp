#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll=long long;


int main(){
 int x,n,min=100,ans=0;
  cin >> x >> n;
 if(n==0) cout << x << endl;
  
 else{
 vector<int> p(n);
  rep(i,n) cin >> p.at(i);
 
 vector<int> con(102,0);
  rep(i,n) con.at(p.at(i))=1;
   
  
 rep(i,102){
  if(con.at(i)==0){ 
   if(abs(x-i)<min){
     min=abs(x-i);
     ans=i;
   }
  }
 }
  cout << ans << endl;
  return 0;
 }  
}
