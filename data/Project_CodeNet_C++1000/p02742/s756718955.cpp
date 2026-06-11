#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
ll h,w;
cin >> h >> w;
if(w == 1 || h == 1){
  cout << 1 << endl;
}
else cout << (h*w+1)/2 << endl;
}
