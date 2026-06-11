#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0;i < (int)(n);i++)

int main() {
  int n, l;
  cin >> n >> l;
  int s = n*(l-1)+n*(n+1)/2;
  if(l<-n+1) cout << s-l-n+1 << endl;
  else if(0<l) cout << s-l << endl;
  else cout << s << endl;
}
