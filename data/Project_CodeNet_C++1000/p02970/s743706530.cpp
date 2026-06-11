#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
int n,d;
cin >> n >> d;
int a = d* 2 + 1;
if(n%a == 0) cout << n/a << endl;
else cout << n/a + 1 << endl;
}
  
