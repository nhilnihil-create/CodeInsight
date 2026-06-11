#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int n;
bool num[123456 * 2 + 1];
vector<int> prime;
void serchPrime(){

  for(int i = 2; i < 123456 * 2 + 1 ; i++){
    if(!num[i]){
      prime.push_back(i);
      for(int k = 1; i * k <= 123456 * 2 ; k++){
        num[i * k] = true;
      }
    }
  }
}

void solve(){
  int res = 0;
  for(int i = 0; i < prime.size(); i++){
    if(n < prime[i] && prime[i] <= 2*n){
      res ++;
    }
  }
  cout << res << endl;
}

int main(){
  serchPrime();
  while(true){
    cin >> n;
    if(n == 0) break;
    solve();
  }

  return 0;
}

