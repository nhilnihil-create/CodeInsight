#include <bits/stdc++.h>
using namespace std;


int gcd(int a, int b) {
    if (b == 0) return a;
    a=a%b;
    return gcd(b, a);
} 

int main() {
  int N;
  cin>>N;
  long long ans=0;
  
  
  for(int a=1;a<=N;a++){
    for(int b=1;b<=N;b++){
      for(int c=1;c<=N;c++){
          ans+=gcd(gcd(a,b),c);
       }
    }
   }
  cout<<ans;
  
  
return 0;
}