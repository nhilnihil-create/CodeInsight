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
  string a,b;
  cin >> a >> b;
  int res = 0;
  for(int i = 0;i < 3;i++){
    if(a[i] == b[i])res++;
  }
  cout << res << endl;
  return 0;
}
