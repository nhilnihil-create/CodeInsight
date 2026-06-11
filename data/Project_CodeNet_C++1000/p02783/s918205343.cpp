#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ;i++)

using namespace std;
using p=pair<int,int>;
typedef long long ll;

int main() {
  int h,a;
  cin >> h >> a;
  int k=h/a;
  if(h%a==0){
    cout << k << endl;
  }
  else{
    cout << k+1 << endl;
  }
  return 0;

}