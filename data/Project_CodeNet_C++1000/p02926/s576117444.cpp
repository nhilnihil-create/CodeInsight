#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

struct dat {
  double x, y;
  double arg;
};

bool cmp(const dat& a, const dat&b){
  return a.arg < b.arg;
}

int main(){
  int N;
  cin >> N;

  dat d[2 * N];
  for(int i = 0; i < N; i++){
    cin >> d[i].x >> d[i].y;
    d[i].arg = atan2(d[i].y, d[i].x);
  }
  sort(d, d + N, cmp);

  for(int i = 0; i < N; i++){
    d[i + N] = d[i];
  }

  /*cout << endl;
  for(int i = 0; i < 2 * N; i++){
    cout << d[i].x << " " << d[i].y << endl;
  }*/

  double ans = 0;
  for(int i = 0; i < N; i++){
    for(int j = i + 1; j <= i + N; j++){
      double sumx = 0;
      double sumy = 0;
      for(int k = i; k < j; k++){
        sumx += d[k].x;
        sumy += d[k].y;
      }
      double tmp = sqrt((sumx) * (sumx) + (sumy) * (sumy));
      ans = max(ans, tmp);
    }
  }

  printf("%.15lf\n", ans);
  //cout << ans << endl;
  return 0;
}
