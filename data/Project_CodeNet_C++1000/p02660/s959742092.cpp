#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define newline '\n'

map<ll, int> primecount;

void primeFactors(ll n)  
{  
    // Print the number of 2s that divide n  
    while (n % 2 == 0)  
    {  
        ++primecount[2];
        n = n/2;  
    }  
  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (ll i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, print i and divide n  
        while (n % i == 0)  
        {  
            ++primecount[i];
            n = n/i;  
        }  
    }  
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)  
        ++primecount[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    primeFactors(n);
    //cout << "done with prime factors\n" << flush;

    int ops = 0;
    for (pair<ll, int> pp: primecount) {
        //ll p = pp.first;
        int cnt = pp.second;
        int i = 1;

        while (true) {
            ++ops;
            if (cnt - i <= i) {
                break;
            }
            cnt -= i;
            ++i;
        }
    }

    cout << ops << newline;

    return 0;
}
