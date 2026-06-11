#include<iostream>
#include<cmath>

using namespace std;

int main(){
  unsigned long long N, ans = 0;

  cin >> N;

  if (N%2==0){
    unsigned long long b = 10;
    while(N >= b){
      ans += N / b;
      b *= 5;
    }
    printf("%llu\n",ans);
  }else{
    printf("0\n");
  }
  
}

