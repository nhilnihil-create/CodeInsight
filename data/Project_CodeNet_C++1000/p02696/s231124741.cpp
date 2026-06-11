#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
ll a,b,n;
cin >> a >> b >> n;
ll z;
if (n >= b) z = b-1;
else z = n;
cout << a*z/b << endl;


return 0;
}



