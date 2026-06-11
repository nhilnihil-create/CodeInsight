#include<bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (int)n; i++)

const int inf = 1'000'000'000;

#include<bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (int)n; i++)

int main(){
  int a,b;
  cin >> a >> b;
  for (int i = 1; i <10001; i++) {
    if ((int)(i*8/100) == a && (int)(i*10/100) == b) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
