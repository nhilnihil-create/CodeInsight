#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int ans = n / 2;
    if(n % 2 == 0) ans--;
    cout << ans << endl;
}
