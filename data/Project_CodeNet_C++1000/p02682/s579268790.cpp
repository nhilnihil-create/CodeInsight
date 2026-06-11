#include <bits/stdc++.h>
using namespace std;

int main() {

  long long a,b,c,k;
  cin>>a>>b>>c>>k;
  int r;
      r=a+b;
      if(a>=k) {
        if(a>k) cout<<k<<endl;
        else
            cout<<k<<endl;
      }
    else if(r>=k){
           cout<<a<<endl;
      }
      else{
         r=k-r;
           cout<<a-r<<endl;
      }
  return 0;
}
