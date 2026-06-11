#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e18;
int si[] = {-1, 0, 1, 0};
int sj[] = {0, -1, 0, 1};

int main(){
  int n;
  cin >> n;

  int count = 0;
  rep(i,n) {
    int d1, d2;
    cin >> d1 >> d2;
    if (d1 == d2) count++;
    else count = 0;
    if(count >= 3){
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}
