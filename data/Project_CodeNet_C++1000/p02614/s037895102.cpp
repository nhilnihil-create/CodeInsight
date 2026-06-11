#include<iostream>
using namespace std;
#include<string>

int main() {
  int h, w, k, bCount;
  cin >> h >> w >> k;
  string str[h];
  for(int i = 0; i < h; i++) {
    cin >> str[i];
  }
  int res = 0;
  for(int bitH = 0; bitH < (1<<h); bitH++) {
    for(int bitW = 0; bitW < (1<<w); bitW++) {
      bCount = 0;
      for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
          if((bitH & (1<<i)) && (bitW & (1<<j))) {
              if(str[i].at(j) == '#') bCount++;
          }
        }
      }
      if(k == bCount) res++;
    }
  }
  cout << res << endl;
  return 0;
}
