#include <iostream>
using namespace std;

int main(){

 int h = 0, w = 0, i;

 while(1) {
  cin >> h >> w;

  if ((h == 0) && (w == 0)) break;

  for (h; h > 0; h--) {
   for (i = w; i > 0; i--) {
    cout << "#";
   }
   cout << endl;
  }
  cout << endl;
 }

 return 0;
}