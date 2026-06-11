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
  string s;
  cin >> s;
  bool res = true;
  for(int i = 0;i < (int)s.size();i++){
    if((i % 2 == 0 && s[i] == 'L') || (i % 2 == 1 && s[i] == 'R'))res = false;
  }
  if(res)cout << "Yes" << endl;
  else cout<< "No" << endl;
}