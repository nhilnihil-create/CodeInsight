#include <bits/stdc++.h>
using namespace std;
#define LL long int
#define ULL unsigned long int
#define LD long double

LL MOD = 1000000007;

int main(){
    int n;
    cin >> n;
    ULL ans = 0;

    for(int i = 1; i <= n; ++i){
        ULL num = n / i;
        ans += num*(num + 1)*i/2;
    }

    cout << ans << endl;

    return 0;
}