#include <iostream>
#include <vector>
#include <string>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  vector<string> a{"Sunny", "Cloudy", "Rainy"};
  int now;
  rep(i, n){
    if (s == a[i]) now = i;
  }
  int next = now + 1;
  if (next == 3) next = 0;
  cout << a[next] << endl;
  
  return 0;
}