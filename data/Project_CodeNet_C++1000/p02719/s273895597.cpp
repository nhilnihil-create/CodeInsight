#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void){
    ll N, K;
    cin >> N >> K;
    
    N %= K;
    ll ans = min(abs(N), abs(N-K));
    cout << ans << endl;
    
    return 0;
}