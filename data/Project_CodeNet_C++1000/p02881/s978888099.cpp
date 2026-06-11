#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin >> N;
  vector<long long>vec;
  for(long long i=1; i*i<=N+1; i++){
    if(N%i == 0){
      vec.push_back( N/i + i - 2);
    }
  }
  sort(vec.begin(),vec.end());
  cout << vec.at(0) << endl;
}
