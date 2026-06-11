#include <iostream>

using namespace std;

int ca(int c){
  int x = 0;
  for(int i=1; i<=c; i++){
    if(c<i) break;
    c-=i;
    x++;
  }
  return x;
}

int main(void){

  long long N;
  int c, ans = 0;

  cin >> N;

  for(long long z=2; z*z<=N; z++){
    c = 0;
    while(true){
      if(N%z==0){
        N = N / z;
        c++;
      }
      else{
        ans += ca(c);
        break;
      }
    }
  }
  if(N!=1) ans++;

  cout << ans << endl;

  return 0;
}
