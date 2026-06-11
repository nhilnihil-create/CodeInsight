#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int main() {
    int a , b , c;
    cin >> a >> b >> c;
    int d = max(a , b);
    if(c % d == 0){
        cout << c / d << endl;
    }
    else{
        cout << c / d + 1 << endl;
    }
}