#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using st = string;
using db = double;
using vll = vector<long long>;
using vvll = vector<vll>;
using vchar = vector<char>;
#define rep(i, m, n) for (int i = (int)(m); i < (int)(n); i++)
#define vrep(vec) for(auto& i : vec)
#define vin(vec) for(auto& i : vec) cin >> i
#define all(v) v.begin(), v.end()
ll mod = 1000000007;

int main(){
  st s;
  cin >> s;
  if(s.size() % 2 == 0){
    bool check = 1;
    rep(i, 0, s.size() / 2){
      if(!(s.at(i * 2) == 'h' && s.at(i * 2 + 1) == 'i')) check = 0; 
    }
    if(check){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}