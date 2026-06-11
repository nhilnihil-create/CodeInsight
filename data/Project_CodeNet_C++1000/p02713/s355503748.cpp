#include <bits/stdc++.h>
using namespace std;

int gcd(int x,int y){
  if(y==0){
    return x;
  }
  return gcd(y,x%y);
}
  
int main(){
  int K,sum=0;
  cin >> K;
  for(int a=1;a<K+1;a++){
    for(int b=1;b<K+1;b++){
      for(int c=1;c<K+1;c++){
        sum+=gcd(a,gcd(b,c));
      }
    }
  }
  cout << sum << endl;
} 