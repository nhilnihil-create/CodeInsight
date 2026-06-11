#include <iostream>
#include <string>
using namespace std;

int main() {

  while( true ) {

    long long int n;
    cin >> n;
    if ( n == 0 ) break;

    long long int ans = 0;

    long long int k = 0;
    long long int l = 0;
    long long int r = 0;

    for ( long long int i = 0; i < n; i++ ) {

      string in;
      cin >> in;

      if ( in == "lu" ) {
	l = 1;
      }else if ( in == "ru" ) {
	r = 1;
      }else if ( in == "ld" ) {
	l = 0;
      }else {
	r = 0;
      }

      if ( k == 0 && l == 1 && r == 1 ) {
	k = 1;
	ans++;
      }
      if ( k == 1 && l == 0 && r == 0 ) {
	k = 0;
	ans++;
      }

    }

    cout << ans << endl;

  }

  return 0;

}