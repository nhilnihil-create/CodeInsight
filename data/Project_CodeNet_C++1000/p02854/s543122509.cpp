#include<bits/stdc++.h>
using namespace std;

int main() {
  long long num;
  long long sum = 0;
  long long Min = 0;
  long long tmp = 0;
  
  cin >> num;
  
  vector<long long> vec(num);
  for(int i = 0; i < num; i++){
    cin >> vec.at(i);
    sum += vec.at(i);
  }
  
  Min = sum;
  for(int i = 0; i < num; i++){
    tmp += vec.at(i);
    Min = min(Min, abs(tmp -(sum - tmp)));
  }
  
  cout << Min;
}
