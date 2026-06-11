#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll a,b,c,d;
  cin>>a>>b>>c>>d;
  ll t,o;
  if(a%d==0) {
t=a/d;
    
  }
  else {
t=a/d+1;
  }
  
    if(c%b==0) {
o=c/b;
    
  }
  else {
o=c/b+1;
  }

  
  if(t>=o) {
cout<<"Yes"<<endl;
  }
else {
cout<<"No"<<endl;
}
}
  
