#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

int main(){
  int a, b, c;
  cin >> a >> b >> c;

  int ans = a - (b + c);

  if(ans >= 0) {
    cout << 0;
    return 0;
  }
  if(ans < 0){
    cout << -1 * ans;
      return 0;
  }
}