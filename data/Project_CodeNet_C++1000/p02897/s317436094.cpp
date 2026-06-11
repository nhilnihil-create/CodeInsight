#include<bits/stdc++.h>
using namespace std;

int main(void){
  int N;
  int k = 0;
  cin >> N;
  for(int i = 1; i <= N; i++){
    if(i % 2 != 0)
      k++;
  }
  printf("%.10f", (double)k / N);
  return 0;
}
