#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <iomanip>//cout << fixed からの cout << setprecision(n) << 小数　によって小数を整数部分含めてn桁表示できるようにする
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
  int r,c;
  int total;
  cin >> r >> c;
  int s[101][101] = {};
  for(int i = 0;i < r; i++){
    for(int j = 0;j < c;j++){
      cin >> s[i][j];
    }
  }
  for(int i = 0;i < r; i++){
    for(int j = 0;j < c;j++){
      total += s[i][j];
    }
    s[i][c] = total;
    total = 0;
  }

  for(int j = 0;j < c+1; j++){
    for(int i = 0;i < r;i++){
      total += s[i][j];
    }
    s[r][j] = total;
    total = 0;
  }
  for(int i = 0;i <= r; i++){
    for(int j = 0;j <= c;j++){
      cout << s[i][j];
      if(j != c){
        cout << " ";
      }
    }
    cout << endl;
  }
  return 0;
}

