#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

int main(){
  int  n, d;
  cin >> n >> d;
  
  int mon = 1 + d * 2;
  int ans = n / mon;
  
  if(n % mon == 0){
    cout << ans;
    return 0;
  }
  cout << ans + 1;
  return 0;
}