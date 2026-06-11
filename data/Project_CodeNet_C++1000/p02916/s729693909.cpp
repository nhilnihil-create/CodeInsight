#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long a[n], b[n], c[n-1];

    for(long long i = 0; i < n; i++) cin >> a[i], a[i]--;
    for(long long i = 0; i < n; i++) cin >> b[i];
    for(long long i = 0; i < n-1; i++) cin >> c[i];

    long long ans = 0;

    for(long long i = 0; i < n; i++){
        ans += b[a[i]];
        if(a[i] + 1 == a[i+1]) ans += c[a[i]];
    }

    cout << ans << endl;
    return 0;
}