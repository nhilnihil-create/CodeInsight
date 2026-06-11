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
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
  int n;
  int b,f,r,v;
  //a[棟][階][部屋]
  int a[4][3][10] = {};
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> b >> f >> r >> v;
    a[b-1][f-1][r-1] += v;
  }
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 3;j++){
      for (int k = 0;k < 10;k++){
        cout <<" "<< a[i][j][k];

      }
      cout << endl;
    }
    if(i != 3){
      cout << "####################" << endl;
    }
  }
  return 0;
}

