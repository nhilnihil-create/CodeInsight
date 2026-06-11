#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

vector<long long> primeFactorize(long long x) {
    vector<long long> res;

    for (long long i = 2; i * i <= x; i++) {
        if (x % i != 0) continue;
        long long ex = 0;

        while(x % i == 0) {
            ex++;
            x /= i;
            res.push_back(pow(i, ex));
        }

    }

    if (x != 1) res.push_back(x);
    return res;
    
}

int main() {
    long long n;
    cin >> n;

    vector<long long> f = primeFactorize(n);

    sort(f.begin(), f.end());
    long long cnt = 0;
    for (long long i = 0; i < f.size(); i++) {
        if (n % f[i] == 0) {
            cnt++;
            n /= f[i];
        }
        if (n < f[i]) break;
    }

    cout << cnt << endl;

}