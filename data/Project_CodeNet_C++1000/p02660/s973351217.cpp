#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

map<ll, int> GetPrimes(ll N) {
    map<ll, int> primes;
    ll p = 2;
    while (p * p <= N) {  // check this cond is correct
        while (N % p == 0) {
            primes[p]++;
            N /= p;
        }
        ++p;
    }
    if (N != 1) {
        primes[N]++;
    }
    return primes;
}

int main()
{
    ll N;
    cin >> N;
    map<ll, int> primes = GetPrimes(N);
    
    int ans = 0;
    for (auto x : primes) {
        int count = x.second;
        int i = 1;
        while (i <= count) {
            ++ans;
            count -= i;
            ++i;
        }
    }
    
    cout << ans << endl;
    return 0;
}
