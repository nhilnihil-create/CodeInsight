#include<iostream>

int main(){
  int d,n,sum;

  while(std::cin >> d){
    n = 600/d;
    for(int i=0;i<n;i++){
      sum += i*i*d*d*d;
    }
    std::cout << sum << std::endl;
    sum = 0;
  }
}