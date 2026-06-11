#include <bits/stdc++.h>
#define rep(i, n) = for(int i=0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int x;
    cin >> x;
    int ans = 0;
    int d;
    d = x / 500;
    ans += d * 1000;
    x -= d * 500;
    d = x / 5;
    ans += d * 5;
    cout << ans << endl;
    return 0;
}