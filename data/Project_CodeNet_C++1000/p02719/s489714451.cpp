#include <bits/stdc++.h>
#include <string>
using namespace std;


int main(){
    int64_t n, k, ans, t;

    cin >> n >> k;

    t = n / k;
    ans = min(n - t * k, (t + 1) * k - n );

    cout << ans << endl;
    
}