#include<bits//stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long int ll;
int k, x, m, n, h, r, w; ll sum = 0,d = 0,c; string s;
int main() {
    cin >> m;
    rep(i, m) {
        cin >> k >> c;
        sum += k * c; d += c;
    }d--; sum--;
    cout << d + sum / 9 << endl;
}