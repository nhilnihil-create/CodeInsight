#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int a, b;
  cin >> a >> b;
  int i = 1;
  for(int i=1; i<=10000000; i++){
    if(i*8/100 == a && i*10/100 == b){
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
