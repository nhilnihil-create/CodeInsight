#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using P = pair<int, int>;
int main(){
    int a;
    ll b,n;
    cin >> a >> b >> n;
    ll m;
    if(n >= b)m = b-1;
    else m = n;
    cout << (ll) (a*m)/b << endl;
}