/* include c++ libraries */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>

/* include c-lang libraries */
#include <climits>
#include <cmath>

/* include my libraries */
//#include <show_vec.hh>

using namespace std;

#define LINE DEBUG{ printf("LINE : %d\n", __LINE__); }
#define DEBUG if(false)

using ll = long long;
template<class T> using vec = vector<T>;

const int MOD = 1000000007;

int main(){
  int A, B, C, D;
  cin >> A >> B >> C >> D;

  int T_attack = C / B;
  if( (C%B) != 0 ) T_attack++;
  int A_attack = A / D;
  if( (A%D) != 0 ) A_attack++;
  if(T_attack <= A_attack){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}
