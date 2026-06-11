#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int N;
  cin >> N;
  
  long long sum = 0;
  int x = N/15;
  for( int i = 1; i <= x; i++) sum += 60+120*(i-1);
  
  for( int i = 15*x+1; i <= N; i++){
     if( i % 3 != 0 && i % 5 != 0 ) sum += i;
  }
  
  printf("%lld\n",sum);
  return 0;
}