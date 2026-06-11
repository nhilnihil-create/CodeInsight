#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int maxp = 1e6 + 5;

vector<bool> primes(maxp, true);

int prefsum[10] = {0, 1, 3, 6, 10, 15, 21, 28, 36, 45};

int main()
{
    ll n, orign;
    int ans = 0, count;
    cin >> n;
    orign = n;
    for(ll i = 2; (i * i) <= orign; i++) {
        if(primes[i]) {
            for(int j = 2; (i * j) * (i * j) <= orign; j++) {
                //cout << i << ' ' << j << ' ' << n << endl;
                primes[i * j] = false;
            }
            count = 0;
            while(!(n % i)) {
                n /= i;
                count++;
                //cout << count << endl;
            }
            if(count) {
                for(int j = 9; j >= 0; j--) {
                    if(count >= prefsum[j]) {
                        ans += j;
                        break;
                    }
                }
            }
        }
    }
    if(n != 1) ans += 1;
    cout << ans;
    return 0;
}
