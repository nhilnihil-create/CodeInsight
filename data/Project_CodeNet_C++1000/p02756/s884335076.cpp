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
    string s;
    cin >> s;
    deque<char> d;
    for (int i = 0; i < s.size(); i++)
    {
        d.push_back(s[i]);
    }
    int q;
    cin >> q;
    bool left_top = true;
    rep(i, q)
    {
        int query;
        cin >> query;
        if(query==1){
            left_top = !left_top;
        }
        else
        {
            int f;
            cin >> f;
            char c;
            cin>>c;
            if(f==1){
                if(left_top){
                    d.push_front(c);
                }else{
                    d.push_back(c);
                }
            }else{
                if(left_top){
                    d.push_back(c);
                }else{
                    d.push_front(c);
                }
            }
        }
    }
    if(!left_top){
        reverse(d.begin(), d.end());
    }
    while(!d.empty()){
        char ans = d.front();
        d.pop_front();
        cout << ans;
    }
    cout << endl;
    return 0;
}