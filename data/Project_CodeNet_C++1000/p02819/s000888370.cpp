#include <bits/stdc++.h>

#define ed cout << "\n";
#define speed                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
#define ffor(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(i, n) ffor(i, 0, n)
#define All(obj) (obj).begin(), (obj).end()
#define INF ((ll)1e9 + 7)
#define c(a) cout << a << "\n";
using namespace std;
const int N = 100005;

void Eratosthenes(int n, vector<int> &primeNum)
{
    vector<bool> sieve(n, true);
    for (int i = 2; i < sqrt(n); i++)
    {
        if (sieve[i])
        {
            for (int j = 0; i * (j + 2) < n; j++)
            {
                sieve[i * (j + 2)] = false;
            }
        }
    }
    int count = 0;
    for (int i = 2; i < n; i++)
    {
        if (sieve[i])
        {
            primeNum.push_back(i);
            count++;
        }
    }
}
int main()
{
    speed;
    cout << fixed << setprecision(6);
    /*start*/
    int x;
    cin >> x;
  
    vector<int> prime;
    Eratosthenes(x, prime);
    int res = 0;
    for (int i = x;; i++)
    {
        bool flag = true;
        for (int p : prime)
        {
            if (i % p == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            res = i;
            break;
        }
    }
    c(res);
    
}
