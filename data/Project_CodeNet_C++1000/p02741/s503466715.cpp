#include<iostream>
#include <vector>
using namespace std;
#define N 32

int main(){
  vector<int> data = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
  
  int K;
  cin >> K;
  
  cout << data.at(K-1) << endl;
}