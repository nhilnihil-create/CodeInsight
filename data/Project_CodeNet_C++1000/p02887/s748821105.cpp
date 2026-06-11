#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  ll b=1;
  char c;
  cin>>c;
  for(ll i=1;i<a;i++){
    char d;
    cin>>d;
    if(c!=d){
      b+=1;
      c=d;
    }
  }
  cout<<b<<endl;
  return 0;
  
      
                        
                        
}
