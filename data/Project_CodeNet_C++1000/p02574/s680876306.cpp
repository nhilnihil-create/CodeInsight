#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<long long> primes;
vector<int> freq(1000'001, 0);

void calc(){
    int n = 1000000;
    vector<char> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

void trial(long long n) {
    for (long long d : primes) {
        if (d * d > n)
            break;
        bool first = true;
        while (n % d == 0) {
            if(first)
                freq[d]++;
            first = false;
            n /= d;
        }
    }
    if (n > 1)
        freq[n]++;
}


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int i, n, m, j, u, v;
    cin >> n;
    calc();
    for(i = 0; i < n; i++){
        cin >> u;
        trial(u);
    }
    for(i = 0; i <= 1000'000; i ++){
        if(freq[i] == n){
            cout << "not coprime" << endl;
            return 0;
        }
    }

    for(i = 0; i <= 1000'000; i ++){
        if(freq[i] > 1){
            cout << "setwise coprime" << endl;
            return 0;
        }
    }
    
    cout << "pairwise coprime" << endl;
}