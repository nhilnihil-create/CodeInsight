using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>

int main(){
  int N, K, fruit;
  cin >> N >> K;
  
  vector<int> fruits;
  for (int i = 0; i < N; i++){
  cin >> fruit;
  fruits.push_back(fruit);
  }
  
  sort(fruits.begin(), fruits.end());
  
  int cost = 0;
  for (int i = 0; i < K; i++) cost += fruits[i];
  
  cout << cost;
  
  return 0;
  
}