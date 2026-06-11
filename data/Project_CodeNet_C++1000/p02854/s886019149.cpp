#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  ll n, s = 0;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; ++i){
    cin >> a[i];
    s += a[i];
  }

  ll sum = 0;
  ll mn = s;
  for(int i=0; i<n; ++i){
    sum += a[i];
    mn = min(mn, abs(sum- (s- sum)));
  }

  cout << mn << endl;

}