#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
const long long mod = 1e9+7;
//////////////////////////////////

int main() {
  int n; cin >> n;
  int cnt = 0;
  int a;
  for(int i=0; i<n; i++) {
    cin >> a;
    if(i%2 == 0 && a%2 == 1) cnt++;
  }
  cout << cnt << endl;
  return 0;
}

// EOF