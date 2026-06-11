#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i< (n);i++)
using namespace std;

int main() {
  long long h,w;
  cin>>h>>w;
  if(h==1||w==1)cout<<1<<endl;
  else if(h%2==0)cout<<(h/2)*w<<endl;
  else{long long a=(h+1)/2,b=(w-1)/2;
    if(w%2==0)cout<<(2*a-1)*(w/2)<<endl;
       else{cout<<(2*a-1)*b+a<<endl;
           }
      }
  
}
