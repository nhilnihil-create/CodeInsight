#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int x;
  cin >> x;
  int k = 1;
  while(1){
    if((k * x) % 360 == 0){
      cout << k << endl;
      exit(0);
    }
    k++;
  }
}
