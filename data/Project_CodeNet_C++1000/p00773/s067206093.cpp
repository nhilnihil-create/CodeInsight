#include <iostream>

using namespace std;

struct sumSet
{
  int small;
  int big;
};

int main(){
  int x, y, s;
  
  while (true) { 
    cin >> x >> y >> s;
    if (x * y * s == 0) {
    break;
    }
    int before[s+1]; 
    int res;
    int tempmax = 0;
    int max = 0;
    max = (s*100 / (100 + x) + 2) * (100 + y) / 100;
    sumSet sumset[s/2 + 1] = {
    };
    for (int i = 1; i <= s; i++) {
      before[i] = i*(100 + x) / 100;
    }
    for (int i = 1; i <= s/2; i++) {
      for (int j = i; j <= s; j++) {
        if (before[i]+before[s-j] == s) {
          sumset[i].small = i;
          sumset[i].big = s-j;
       }
      } 
    }

    for (int i = 1; i <= s/2; i++) {
      res = sumset[i].small * (100 + y) / 100 + sumset[i].big * (100 + y) / 100;
      if (res == max) {
        tempmax = max;
        break;
      }
      else if(res < max && tempmax < res) {
        tempmax = res;
        continue;
      }
      else if (res < max && res < tempmax) {
        continue;
      }
    }
    cout << tempmax << endl;
  }
  return 0;
}