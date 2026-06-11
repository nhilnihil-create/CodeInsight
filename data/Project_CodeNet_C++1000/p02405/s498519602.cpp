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
  int h,w;
  while(1){
    cin >> h >> w;
    if(h == 0 && w == 0) break;
    for(int i = 0; i < h; i++){
      if(i % 2 == 0){
        for(int j = 0; j < w; j++){
          if(j % 2 == 0){
            cout << "#";
          }else{
            cout << ".";
          }
        }
      }else{
        for(int j = 0; j < w; j++){
          if(j % 2 == 0){
            cout << ".";
          }else{
            cout << "#";
          }
        }
      }
    cout << endl;

    }
    cout << endl;
  }
  return 0;
}

