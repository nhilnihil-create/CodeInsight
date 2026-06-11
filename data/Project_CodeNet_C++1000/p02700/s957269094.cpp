#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int e , f;
    e = a / d;
    f = c / b;
    if(a % d != 0) ++e;
    if(c % b != 0) ++f;
    if(e >= f) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}