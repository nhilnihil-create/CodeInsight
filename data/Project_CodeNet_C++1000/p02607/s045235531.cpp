#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define repi(i,n) for(int i=0; i<(n); i++)

int main() {
  int N, count=0;
  cin >> N;
  vector<int> num(N);
  repi(i,N) cin >> num.at(i);
  for(int i=0; i<N; i+=2) if(num.at(i)%2==1) count++;
  cout << count << endl;
  return 0;
}