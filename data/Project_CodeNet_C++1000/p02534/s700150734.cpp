#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define PI 2 * acos(0)
#define ones(n) __builtin_popcount(n)
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 9000000
#define debug(x) cerr << #x << " = " << x << '\n';
#define LOOP printf("LOOP!!")
#define READ freopen("input.txt", "r", stdin)
#define PRINT freopen("output.txt", "w", stdout);
#define print(a, b) printf("Case %d: %lld\n", a, b)
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9 + 7;
using namespace std;
const int VAL = 20000000;
bool isprime[VAL + 10];

///prime storage>>
vector<ll> prime;
void primes()
{

    for (int i = 0; i <= VAL; i++)
        isprime[i] = true;

    for (int i = 3; i * i <= VAL; i++)
    {
        if (isprime[i])
        {

            for (int j = i * i; j <= VAL; j += i)
                isprime[j] = false;
        }
    }
    prime.push_back(2);
    for (int i = 3; i <= VAL; i += 2)
        if (isprime[i])
            prime.push_back(i);
}

/************MAIN_FUNCTION**********/
int main(int argc, char *argv[])
{

    string s = "ACL";

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cout << s;

    cout << '\n';

    return 0;
}