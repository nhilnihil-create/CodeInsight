#include <iostream>
#define ill long long
#define rep(i, a, b) for(ill i = a; i < b; i++)
using namespace std;

int main() {
  int x;
  cin >> x;
  rep(i, -500, 501) {
    rep(j, -500, 501) {
      if(i*i*i*i*i - j*j*j*j*j == x) {
        cout << i << " " << j << "\n";
        return 0;
      }
    }
  }
}
