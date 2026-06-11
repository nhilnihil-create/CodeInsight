#include<bits/stdc++.h>
using namespace std;

int main(void){
  int N;
  bool ans = false;
  cin >> N;

  for(int i = 1; i <= 9; i++){
    for(int j = 1; j <= 9; j++){
      if(i * j == N){
	ans = true;
	break;
      }
    }
  }

  if(ans == true)
    printf("Yes\n");
  else
    printf("No\n");
  
  return 0;
}