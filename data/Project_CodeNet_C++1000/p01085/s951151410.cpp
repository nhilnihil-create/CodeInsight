#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = (int)1e9;

int main() {
  while(true) {
    int m, nmin, nmax;
    cin >> m >> nmin >> nmax;
    if(m == 0 && nmin == 0 && nmax == 0) break;
    vector<int> p(m);
    for(int i = 0; i < m; ++i) cin >> p[i];
    int ansgap = 0;
    int ansac = -1;
    for(int point = 0; point <= 10000; ++point) {
      int acmin = INF;
      int wamax = 0;
      int numac = 0;
      for(int i = 0; i < m; ++i) {
        if(p[i] >= point) {
          acmin = min(acmin, p[i]);
          numac++;
        }
        else {
          wamax = max(wamax, p[i]);
        }
      }
      if(nmin <= numac && numac <= nmax) {
        if(ansgap < acmin - wamax || (ansgap == acmin - wamax && ansac < numac)) {
          ansgap = acmin - wamax;
          ansac = numac;
        }
      }
    }
    cout << ansac << endl;
  }
}