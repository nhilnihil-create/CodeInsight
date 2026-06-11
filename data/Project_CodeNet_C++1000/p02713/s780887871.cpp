#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
  if(b == 0){
    return 0;
  }
 else if(a%b == 0){
    return b;
  }
else{
  return gcd(b, a%b);
}
}


int main(){
	int K;
    cin >> K;
  int sum = 0;
    for(int i=1;i<K+1;++i){
     for(int j=1;j<K+1;++j){
       for(int l=1;l<K+1;++l){
         sum += gcd(gcd(i,j),l);
       }
     }
    }
  cout << sum << endl;
 
}
