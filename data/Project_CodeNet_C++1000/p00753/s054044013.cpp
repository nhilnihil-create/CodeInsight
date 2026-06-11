#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
  bool p[1000000];
  memset(p, 1, sizeof(p));
  
  p[1] = p[0] = 0;
  for(int i = 0 ; i < 1000000 ; i++){
    if(p[i]){
      for(int j = 2 * i ; j < 1000000 ; j += i){
	p[j] = 0;
      }
    }
  }
  int n;
  while(cin >> n, n){
    int cnt = 0;
    for(int i = n+1 ; i <= 2 * n ; i++){
      if(p[i] == 1) cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}

 