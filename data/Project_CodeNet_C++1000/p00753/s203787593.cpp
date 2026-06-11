#include<iostream>
#include<algorithm>
using namespace std;
bool isPrime[400010];

void init(){
  fill(isPrime,isPrime+400010,true);
  isPrime[0] = isPrime[1] = false;
  for(int i = 2;i*i < 400010;i++){
    if(isPrime[i]){
      for(int j = i*2;j < 400010; j += i){
        isPrime[j] = false;
      }
    }
  }
}

int main(){
  init();
  while(true){
    int n;
    cin >> n;
    if(n == 0)break;
    int cnt = 0;
    for(int i = n+1;i <= n*2;i++){
      if(isPrime[i])cnt++;
    }
    cout << cnt << endl;
  }
}