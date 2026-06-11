#include <iostream>
#include <vector>
using namespace std;

vector<int> res;

void Prime_factorize(int n){
  for(int i = 2 ; i*i <= n ; i++){
    while(n%i==0){
      res.push_back(i);
      n /= i;
    }
  }
  if(n != 1) res.push_back(n);
}

int main(){
  int n;
 
  cin >> n;
  cout << n << ':';

  Prime_factorize(n);

  for(int i = 0 ; i < res.size() ; i++){
    cout << " " << res[i];
  }
  cout << endl;

  return 0;
}