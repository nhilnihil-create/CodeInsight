#include <iostream>

#define SIZE_MAX 150

using namespace std;

int main(void)
{
  int h, w;
  while (cin >> h >> w && h > 0) {
//    cout << "in:" << h << ", " << w << endl;
    const int inDiag = h*h + w*w;
    int minDiag = 0x7FFFFFFF;
    int minW = SIZE_MAX, minH = SIZE_MAX;


    for (int x = 1; x <= SIZE_MAX; x++) {
      for (int y = 1; y < x; y++) {


	int diag = y*y + x*x;

	if (diag > inDiag && diag < minDiag) {
	  minH = y;
	  minW = x;
	  minDiag = diag;
	} else if (diag == inDiag && y > h && y < minH) {
	  minH = y;
	  minW = x;
	  minDiag = diag;
	} else if (diag > inDiag && diag == minDiag && y < minH) {
	  minH = y;
	  minW = x;
	  minDiag = diag;
	}
      }
    }
    cout << minH << " " << minW << endl;
  }
  return 0;
}