#include <iostream>
using namespace std;

int main() {
  const int N = 4;
  int a[N], b[N];
  while(cin >> a[0]) {
    for(int i = 1; i < N; ++i) cin >> a[i];
    for(int i = 0; i < N; ++i) cin >> b[i];
    int hit, blow;
    hit = blow = 0;
    for(int i = 0; i < N; ++i) {
      for(int j = 0; j < N; ++j) {
	if(a[i] == b[j]) {
	  if(i == j) ++hit;
	  else ++blow;
	}
      }
    }
    cout << hit << " " << blow << endl;
  }
  return 0;
}