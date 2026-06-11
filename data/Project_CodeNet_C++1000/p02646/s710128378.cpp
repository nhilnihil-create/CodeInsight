#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll a,b,v,w,t;
    cin >> a >> v;
    cin >> b >> w;
    cin >> t;
    string ans = "NO";
    if(abs(b-a)+(w-v)*t <= 0) ans = "YES";
    cout << ans;
}