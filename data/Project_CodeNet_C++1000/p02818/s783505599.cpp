#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
    ll a, b, k;
    cin >> a >> b >> k;

    if(k <= a) cout << a - k << " " << b << endl;
    else if(k <= a + b) cout << 0 << " " << b - (k - a) << endl;
    else cout << 0 << " " << 0 << endl;
   return 0;
}