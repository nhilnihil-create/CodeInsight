#include <bits/stdc++.h>
using namespace std;

int n;
int c;
int s;
int res;

int main(){
  cin >> n;
  for(int i = 1; i <= n; ++i){
    c = 0;
    s = i;
    while(s > 0){
      c += 1;
      s /= 10;
    }
    if(c % 2 == 1){
      res += 1;
    }
  }
  cout << res << endl;
}