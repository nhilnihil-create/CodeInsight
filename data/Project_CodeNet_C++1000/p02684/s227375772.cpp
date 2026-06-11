#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <iomanip>
#include <limits>
using namespace std;
// 素因数分解
typedef pair<long long, long long> P;
vector<P> prime_factorize(long long n)
{
    vector<P> res;
    for (long long p = 2; p * p <= n; ++p)
    {
        if (n % p != 0)
            continue;
        int num = 0;
        while (n % p == 0)
        {
            ++num;
            n /= p;
        }
        res.push_back(make_pair(p, num));
    }
    if (n != 1)
        res.push_back(make_pair(n, 1));
    return res;
}
// 因数分解
long long gcd(long long x, long long y)
{
    if (y == 0)
    {
        return x;
    }
    else
    {
        return gcd(y, x % y);
    }
}
const int MOD = 1000000007;
typedef long long unsigned int ll;
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
    int n;
    ll k;
    cin >> n >> k;
    vector<int> A(n);
    rep(i, n)
    {
        cin >> A[i];
        A[i]--;
    }
    deque<int> a;
    vector<bool> seen(n, false);
    int cur = 0;
    while(true){
        if(seen[cur]){
            while(a[0]!=cur){
                k--;
                a.pop_front();

                if (k == 0){
                    cout << a[0] + 1 << endl;
                    return 0;
                }
            }
            break;
        }
        a.push_back(cur);
        seen[cur] = true;
        cur = A[cur];
    }
    cout << a[k % a.size()] + 1 << endl;
    return 0;
}