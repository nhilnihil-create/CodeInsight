#include <iostream>
#include <vector>
using namespace std;
using ll = long long int;

namespace MY {
template<typename T>
T min(T a, T b) {
  if (a < b) {return a;}
  else {return b;}
}
template<typename T>
T max(T a, T b) {
  if (a > b) {return a;}
  else {return b;}
}
}

int main() {
  ll N;
  cin >> N;
  
  vector<ll> monster;
  for (int i = 0; i <= N; i++) {
  	ll ai;
    cin >> ai;
    monster.push_back(ai);
  }
  vector<ll> brave;
  for (int i = 0; i < N; i++) {
    ll bi;
    cin >> bi;
  	brave.push_back(bi);
  }
  
  ll sum = 0;
  for (int i = 0; i < N; i++) {
  	sum += MY::min(monster[i], brave[i]);
    brave[i] -= MY::min(monster[i], brave[i]);
    
    sum += MY::min(monster[i + 1], brave[i]);
    monster[i + 1] -= MY::min(monster[i + 1], brave[i]);
  }
  cout << sum << endl;
}