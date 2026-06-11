#include <bits/stdc++.h>
#include <vector>
#include <string.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
//#define INF 2e9
#define ALL(v) v.begin(), v.end()
 
using namespace std;
typedef long long ll;

int main(){
  int x;
  float temp1,temp2,temp;
  bool ans=false;
  cin >> x;
  if(x<100){
      cout << 0 << endl;
      return 0;
  }
  if(x%100==0) ans=true;

  temp1 = x%100;
  temp2 = x/100;
  temp = temp1/temp2;

  if(temp<=5.0){
      ans = true;
  }
  cout << (ans? 1:0) << endl;
  return 0;
}