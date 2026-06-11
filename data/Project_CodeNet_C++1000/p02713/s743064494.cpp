#include <bits/stdc++.h>
using namespace std;
using ll = long long;
unsigned gcd( unsigned a, unsigned b){
  
  if( !b ) return 0;
  if( a%b == 0 ) return b;
  else gcd( b, a%b );
  
}


int main(){
  
  int K;
  cin >> K;
  ll sum = 0;
  for( int i=1; i<= K; i++){
      for( int j=i; j<= K; j++){
        for( int l=j; l<= K; l++){
            
          if( i==j && j==l )sum += gcd(gcd( i,j ),l);
          else if( i==j || j==l )sum += 3*gcd(gcd( i,j ),l);
          else sum += 6*gcd(gcd( i,j ),l);

          }
      }
  }
  
  printf("%d\n",sum);
  return 0;
}
