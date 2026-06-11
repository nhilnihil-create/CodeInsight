#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
  int x;
  cin >> x;
  for(int i=-1000; i<=1000; i++){
    for(int j=-1000; j<=1000; j++){
      if(pow(i,5) - pow(j,5) == x){
        cout << i << " " << j << endl;
        return 0;
      }
    }
  }
}
