#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<ll, ll>;
#define rep(i, n)  for (int i = 0; i <  (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(x) (x).begin(), (x).end()
const ll INF = ll(1e18)+1;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll x;
    cin >> x;

    if(x <= 599) cout << 8;
    if(600 <= x && x <= 799) cout << 7;
    if(800 <= x && x <= 999) cout << 6;
    if(1000 <= x && x <= 1199) cout << 5;
    if(1200 <= x && x <= 1399) cout << 4;
    if(1400 <= x && x <= 1599) cout << 3;
    if(1600 <= x && x <= 1799) cout << 2;
    if(1800 <= x) cout << 1;
}