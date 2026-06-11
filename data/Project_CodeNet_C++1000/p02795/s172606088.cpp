#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
const long long mod = 1e9+7;
//////////////////////////////////

int main(){
  int h, w, n; cin >> h >> w >> n;
  cout << (n + max(h, w) - 1) / max(h, w) << endl;
}

// EOF