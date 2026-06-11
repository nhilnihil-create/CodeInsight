#include <bits/stdc++.h>
 using namespace std;

int main(){
  long long N,i,j;
  cin >> N;
  int res = 0;

  for(i=2;i*i<=N;i++){
    j = i;
	while(N % j == 0){
      res++;
      N /= j;
      j *= i;
    }
    while(N % i == 0)
      N /= i;
  }
  if (N > 1)
    res++;

  cout << res << endl;
}