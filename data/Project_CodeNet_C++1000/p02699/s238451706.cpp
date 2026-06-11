#include <iostream>
using namespace std;

int main() {
	int S,W;
  cin >> S;
  cin >> W;
  if (W>=S) cout << "unsafe";
  if (W<S) cout << "safe";
	return 0;
}
