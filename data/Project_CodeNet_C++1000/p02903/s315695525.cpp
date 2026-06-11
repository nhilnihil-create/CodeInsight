#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int main(){
  int h,w,a,b;
  cin >> h >> w >> a >> b;
  //if(a == 0)a++;
  //if(b == 0)b++;
  for(int i = 0;i < h;i++){
    for(int j = 0;j < w;j++){
      if((i < b ^ j < a))cout << 0;
      //else if(h >= 2 && w >= 2 && i >= h - b - 1 && j >= w - a - 1)cout << 0;
      else cout << 1;
    }
    cout << endl;
  }
  return 0;
}