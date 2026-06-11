#include <iostream>
#include <vector>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;

int main() {

  string S;
  cin >> S;

  int n = S.size();

  bool flg = 1;
  rep(i, n) {
	if (i%2 == 0) {
	  if (S[i] == 'L') {
		flg = 0;
		break;
	  }
	} else {
	  if (S[i] == 'R') {
		flg = 0;
		break;
	  }
	}
  }

  if (flg) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}