#include <iostream>
#include <vector>
using namespace std;

long long getResult(const vector<long long> &stockPrices, const long long days){
  long long cash = 1000;
  long long stockCount = 0;

  for(uint i = 0; i < days; i++){
    if(i == days - 1 || stockPrices[i] >= stockPrices[i+1]){
      cash += stockCount * stockPrices[i];
      stockCount = 0;
    }else{
      stockCount += cash / stockPrices[i];
      cash %= stockPrices[i];
    }
  }
  return cash;
}

int main(){
  long long N;
  cin >> N;
  
  vector<long long> A(N);
  for(long long i = 0; i < N; i++){
    cin >> A[i];
  }
  
  long long result = getResult(A, N);
  cout << result << endl;
  
  return 0;
}