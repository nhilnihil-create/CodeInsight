#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  int ans = abs((a+b)/2);
  if((a+b)%2 == 0){
    cout << ans;
    return 0;
  }
  else cout << "IMPOSSIBLE";
  return 0;
}