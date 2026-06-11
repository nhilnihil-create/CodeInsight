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
typedef long long int ll;
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define rep(i, n) for (int i = 0; i < (n); i++)

void rec(int d,ll val,vector<ll> &all){
    all.push_back(val);

    if(d==10){
        return;
    }
    for (int j = -1; j <= 1;j++){
        int add = (val % 10) + j;
        if(0<=add&&add<=9){
            rec(d + 1, val * 10 + add, all);
        }
    }
}

int main()
{
    int k;
    cin >> k;
    vector<ll> all;
    for (int v = 1; v < 10;v++){
        rec(1, v, all);
    }
    sort(all.begin(), all.end());
    cout << all[k - 1] << endl;
    return 0;
}