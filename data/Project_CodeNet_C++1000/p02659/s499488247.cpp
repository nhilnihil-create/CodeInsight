#include <bits/stdc++.h>
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
typedef long long ll;
using namespace std;

int main(){
    long double b;
    ll a;
    cin >> a >> b;
    
    ll b_ = ll(b*100+0.01);
    
    cout << a*b_/100 << endl;
}