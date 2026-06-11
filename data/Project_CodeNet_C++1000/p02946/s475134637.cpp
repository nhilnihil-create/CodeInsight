#include<bits/stdc++.h>
using namespace std;

int main(){
  int K,X,A=1000000;
  cin >> K >> X;
  for(int i=X-K+1;i<X+K;i++){
    if(-A-1<i && i<A+1){
      cout << i;
    }
    if(i==A || i==X+K){
      cout << endl;
    }
    else{
      cout << " ";
    }
  }
}