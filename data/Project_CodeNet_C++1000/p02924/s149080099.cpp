#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N;
    cin >> N;
    ll ans =0;
    for(int i=0;i<N;i++){
        ans += i;
    }
    cout << ans << endl;
    return 0;
}