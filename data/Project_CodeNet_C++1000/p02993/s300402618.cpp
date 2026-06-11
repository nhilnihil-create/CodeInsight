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
  for(int i = 0;i < 3;i++){
    if(s[i] == s[i + 1])res = false;
  }
  if(res)cout << "Good" << endl;
  else cout << "Bad" << endl;
}