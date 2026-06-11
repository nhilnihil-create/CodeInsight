#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll W,H,x,y;
  cin>>W>>H>>x>>y;
  if(W*H%2!=0) {
cout<<W*H/2+0.5<<" ";
  }
  else {
cout<<W*H/2<<" ";
  }
  if(W%2!=0||H%2!=0) {
cout<<0<<endl;
    return 0;
  }
  else if(W/2==x&&H/2==y) {
cout<<1<<endl;
  }
  else {
cout<<0<<endl;
  }
}
  
  
  
  
  
  

  
  
