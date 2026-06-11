#include <iostream>

using namespace std;
const int lim = 1e7 + 1;
int lp[lim] , n;
void sieve(){
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i)
            lp[j] += 1;
}
int main(){
    cin >> n;
    sieve();
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        ans = ans + 1LL * lp[i] * i;
    cout << ans;
    return 0;
}