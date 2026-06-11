#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<char> c(N);
  int red = 0;
  for(int i=0; i<N; i++){
    cin >> c.at(i);
    if(c.at(i)=='R') red++;
  }
  int white = N - red;
  vector<int> p(N+1);
  int leftW = 0, rightR = red;
  p.at(0) = rightR;
  p.at(N) = N - rightR;
  for(int i=1; i<N; i++){
    if(c.at(i-1)=='R') rightR--;
    if(c.at(i-1)=='W') leftW++;
    p.at(i) = max(leftW, rightR);
  }
  sort(p.begin(), p.end());
  cout << p.front();
  return 0;
}