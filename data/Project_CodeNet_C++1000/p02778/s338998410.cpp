
#include <math.h>

#include <algorithm>

#include <iostream>

#include <string>

using namespace std;
#define endl '\n'

//////////////////////////////////////////////////////////////////////////
/* Custom function starts here */

/* Custom function ends here: */
//////////////////////////////////////////////////////////////////////////////

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);

  /* MAIN Code STARTS here: */
    string s;
    cin >> s;
    int size = s.size();
    for(int i = 0; i < size; i++){
        s[i] = 'x';
    }
    cout << s << endl;

  /* MAIN Code ENDS here: */
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}