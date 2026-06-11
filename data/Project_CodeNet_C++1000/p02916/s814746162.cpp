#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  vector<int> b(N);
  vector<int> c(N);
  for(int i = 0; i < N; i++){
    cin >> a.at(i);
  }
  for(int i = 0; i < N; i++){
    cin >> b.at(i);
  }
  for(int i = 0; i < N; i++){
    cin >> c.at(i);
  }
  int sum = 0;
  for(int i = 0; i < N; i++){
    sum += b.at(a.at(i)-1);
    if(i > 0){
      if(a.at(i) - a.at(i - 1) == 1)sum += c.at(a.at(i-1)-1);
    }
  }
  cout << sum << endl;
}