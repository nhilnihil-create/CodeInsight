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
  ll m = 0;
  cin >> m;
  ll keta = 0;
  ll all = 0;
  for(int i = 0;i < m;i++){
    ll d,c;
    cin >> d >> c;
    all += d * c;
    keta += c;
  }
  cout << keta - 1 + (all - 1) / 9 << endl;
}