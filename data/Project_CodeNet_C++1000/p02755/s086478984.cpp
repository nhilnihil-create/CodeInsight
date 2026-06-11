#include <bits/stdc++.h>
using namespace std;
typedef long double ll;

ll A, B;

int main() { 
    cin >> A >> B;
    ll out = -1;
    for (double i = B; i <= 2000; i++) {
      if (int(i*0.08)==A && int(i*0.1)==B) {
          out = i;
          break;
      }
    }
    cout << out << endl;
    return 0;
}
