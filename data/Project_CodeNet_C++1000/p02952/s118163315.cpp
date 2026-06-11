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
  ll n = 0;
  cin >> n;
  ll res = 0;
  for(int i = 1;i <= n;i++){
    string s = to_string(i);
    if(s.size() % 2 == 1)res++;
  }
  cout << res << endl;
}