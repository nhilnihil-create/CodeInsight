#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
int x,y;
cin >> x >> y;
vector<int> a = {300000,200000,100000};
int ans = 0;
if(x <= 3)ans += a.at(x-1);
if(y <= 3)ans += a.at(y-1);
if(x == 1 && y == 1) ans += 400000;
cout << ans << endl;
}
