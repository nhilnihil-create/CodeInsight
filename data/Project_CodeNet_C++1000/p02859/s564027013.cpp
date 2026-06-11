//templates
#include <iostream>
#include <algorithm>
#include <string>
#include <numeric>
#include <vector>
#include <unordered_map>
#include <map>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <queue>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define sort_key(struct_name,key_name) [](const struct_name &x, const struct_name &y){return x.key_name < y.key_name;}
#define pb(x) push_back(x)
typedef long long ll;
const long long MOD = 1e9 + 7;
using namespace std;

//main
int main(){
  int r; cin >> r;
  cout << r*r << endl;
}
