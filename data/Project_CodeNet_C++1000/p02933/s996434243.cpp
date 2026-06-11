#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
using ll = long long;
using P = pair<int,int>;

int main() {
  int a;
  string s;
  cin >> a >> s;

  if(a>=3200) {
    cout << s << endl;
  } else if(a<3200){
    cout << "red" << endl;
  }
  return 0;
}