#include <iostream>

using namespace std;

int const NMAX = 1e6;

bool ciur[1 + NMAX];

void computeCiur(){
  for(long long i = 2;i * i <= NMAX;i++){
    if(ciur[i] == 0){
      for(long long j = i * i;j <= NMAX;j+=i){
        ciur[j] = 1;
      }
    }
  }
}

int main() {

  int n;
  cin >> n;
  computeCiur();
  while(ciur[n] == 1){
    n++;
  }
  cout << n;
  return 0;
}
