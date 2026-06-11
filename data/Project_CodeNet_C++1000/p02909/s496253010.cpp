#include <iostream>
#include <vector>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;

int main() {

  string S;
  cin >> S;

  vector<string> W = {"Sunny", "Cloudy", "Rainy", "Sunny"};

  rep(i, 3) {
	if (S == W[i]) {
	  cout << W[i+1] << endl;
	  break;
	}
  }

  return 0;
}