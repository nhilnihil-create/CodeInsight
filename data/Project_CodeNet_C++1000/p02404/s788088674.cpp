#include <iostream>
using namespace std;

int main(){

 int h, w, i, j;

 while(1) {
  cin >> h >> w;

  if ((h == 0) && (w == 0)) break;

  for (i = h; i > 0; i--) {
   for (j = w; j > 0; j--) {
    if (i == h || i == 1) cout << "#";
    else if (j == w || j == 1) cout << "#";
    else cout << ".";
   }
   cout << endl;
  }
  cout << endl;
 }

 return 0;
}