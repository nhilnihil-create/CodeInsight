#include <bits/stdc++.h>
#include <math.h>
using namespace std;
using ll = long long;
int main() {
  ll a,b,c,k;
  cin>>a>>b>>c>>k;
  if(k<a){
    cout<<k<<endl;
    return 0;
  }
  else if(k<=a+b){
    cout<<a<<endl;
    return 0;
  }
  else{
    cout<<a-(k-a-b)<<endl;
  }
    
  
}
