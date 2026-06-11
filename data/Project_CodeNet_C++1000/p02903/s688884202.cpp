#include <iostream>

using namespace std;


int ans[1005][1005];

int main() {
  int h,w,a,b;
  cin >> h >> w >> a >> b;

  for(int i = 0; i < h; i++) {
    if(i < b) {
      for(int j = 0; j < w; j++) {
	if(j < a) ans[i][j] = 0;
	else ans[i][j] = 1;
      }
    }
    else {
      for(int j = 0; j < w; j++) {
	if(j < a) ans[i][j] = 1;
	else ans[i][j] = 0;
      }
    }
  }

  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      cout << ans[i][j];
    }
    cout << endl;
  }
}
