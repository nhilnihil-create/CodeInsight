#include <iostream>

using namespace std;

int gcd(int a, int b){
  if(a%b==0) return b;
  return gcd(b, a%b);
}

int main(void){

  int K;
  int ji, sum = 0;

  cin >> K;

  for(int i=1; i<=K; i++){
    for(int j=1; j<=K; j++){
      ji = gcd(j, i);
      for(int k=1; k<=K; k++){
        sum+=gcd(k, ji);
      }
    }
  }

  cout << sum << endl;
}