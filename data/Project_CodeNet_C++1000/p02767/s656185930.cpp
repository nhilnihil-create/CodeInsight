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

int main()
{
    int N;
    cin >> N;
    vector<int> X(N);
    rep(i,N){
        cin >> X[i];
    }
    sort(X.begin(), X.end());
    int start = X[0];
    int end = X[N-1];
    //cout << start <<" "<< end << endl;
    ll dis = 10000000000;
    for (int i = start; i <= end; i++)
    {
        ll add = 0;
        for (int j = 0; j < N; j++)
        {
            add +=(i - X[j])*(i - X[j]);
        }
        dis = min(dis, add);
        //cout << add << endl;
    }
    cout << dis << endl;
    return 0;
}