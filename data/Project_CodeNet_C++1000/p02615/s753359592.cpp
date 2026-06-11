#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i, n)   for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n;  cin >> n;
    vector<ll>a(n);
    rep(i, n)   cin >> a[i];
    sort(a.rbegin(), a.rend());
    ll ans = 0;
    for(int i = 1; i < n; i++){
        ans += a[i/2];
    }
    cout << ans << endl;
}
