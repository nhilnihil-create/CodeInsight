#include <bits/stdc++.h>
using namespace std;
int main(){
        int k; cin >> k;
        long long int ans = 0;
        for (int x = 1; x <= k; ++x){
            for (int y = 1; y <= k; ++y){
                for (int z = 1; z <= k; ++z){
                    ans += __gcd(x, __gcd(y, z));
                }
            }
        }
        cout << ans << endl;
    return 0;
}

