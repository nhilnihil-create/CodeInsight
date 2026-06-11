#include <iostream>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long N;
  cin >> N;
  cout << (N * (N - 1)) / 2 << endl;

  return 0;
}
