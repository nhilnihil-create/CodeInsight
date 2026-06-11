#include <bits/stdc++.h>
using namespace std;
#define mp make_pair

int main(){
    int n; cin >> n;
    long long ans = 0;
    for (long long i=1; i!=n+1; i++){
        ans += i * (n-i+1);
    }
    for (long long i=1; i!=n; i++){
        long long a, b; cin >> a >> b;
        ans -= min(a, b) * (n - max(a, b)+1);
    }
    cout << ans << endl;
    return 0;
}