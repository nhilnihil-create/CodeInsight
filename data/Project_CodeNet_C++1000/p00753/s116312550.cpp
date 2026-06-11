#include <iostream>
using namespace std;

bool is_prime[250000];
void set_prime(){
  for(int i = 0; i < 250000; i++) is_prime[i] = true;
  is_prime[0] = false;
  is_prime[1] = false;
  for(int i = 2; i <= 500; i++){
    if(is_prime[i]){
      for(int j = i * i; j < 250000; j += i) is_prime[j] = false;
    }
  }
}

int main(void){
  int n, ans;
  set_prime();
  while(1){
    cin >> n;
    if(n == 0) break;
    ans = 0;
    for(int i = n + 1; i < n * 2 + 1; i++){
      if(is_prime[i]) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
