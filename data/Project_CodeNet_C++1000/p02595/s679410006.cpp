#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int n;
  ll d;
  cin >> n >> d;

  ll x, y;
  int cnt = 0;
  for(int i=0; i<n; ++i){
    cin >> x >> y;
    if(x*x + y*y <= d*d) cnt++;
  }
  cout << cnt << endl;
}


