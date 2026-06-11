#include<iostream>
#define ll long long int

using namespace std;

ll gcd2(int a,int b){
  if(a % b == 0) return b;
  return gcd2(b,a%b);
}

ll gcd3(int a,int b,int c){
  return gcd2(gcd2(a,b),c);
}

int main(void){
  ll K,sum=0;
  cin >> K;
  for(int i=1;i <= K;i++){
    for(int j=1;j <= K;j++){
      for(int k=1;k <= K;k++){
        sum += gcd3(i,j,k);
      }
    }
  }
  cout << sum << endl;
  return 0;
}
