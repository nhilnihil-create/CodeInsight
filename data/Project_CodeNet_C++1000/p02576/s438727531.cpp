#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int n, x, t;
  cin >> n >> x >> t;

  int ans = (n+(x-1)) / x;
  int ans1 = ans * t;

  cout << ans1;

}