#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
int64_t MAX = 9223372036854775807;
double PI = 3.141592653589793;

int64_t gcd(int64_t p, int64_t q)
{
    if (p < q)
        swap(p, q);

    if (p % q == 0)
        return q;
    else
        return gcd(q, p % q);
}

map<int64_t, int64_t> bunkai(int64_t N)
{
    map<int64_t, int64_t> hist;

    int64_t a = 2;
    while (N >= a * a)
    {
        if (N % a == 0)
        {
            hist[a]++;
            N /= a;
        }
        else
            a++;
    }
    hist[N]++;
    return hist;
}

int main()
{
    int64_t A, B, ans = 0;
    cin >> A >> B;
    int64_t g = gcd(A, B);
    if (g > 1)
        ans++;
    auto x = bunkai(g);
    cout << ans + x.size();
}