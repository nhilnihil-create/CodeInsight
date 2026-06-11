#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x = (a + d - 1)/d;
    int y = (c + b - 1)/b;
    cout << (x >= y ? "Yes" : "No") << endl;
    return 0;
}