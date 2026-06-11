#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18
#define PI 3.14159265358979

using namespace std;

int main(void){
  ll h, w, a, b;
  cin >> h >> w >> a >> b;
  
  if (a > w - a || b > h - b){
    cout << "No" << endl;
  }
  else {
    for (int i = 0; i < h; i++){
      for (int j = 0; j < w; j++){
        if ((j < a) ^ (i < b)){
          cout << "1";
        }
        else
          cout << "0";
      }

      cout << endl;
    }
  }

  return 0;
}
