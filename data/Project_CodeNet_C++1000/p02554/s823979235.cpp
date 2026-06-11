/**
 * Author : RDP
 * There are no two words in the English language more harmful than "good job".
 * 1729 ;)
**/
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <bitset>
#include <iomanip>
#include <cassert>
#include <numeric>
using namespace std;
using ll = long long;
#define endl '\n'
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) 
{
  cerr << " " << to_string(H);
  debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define FAST_IO ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define bp(x) __builtin_popcount(x)
#define zf(x) __builtin_clz(x)
#define zl(x) __builtin_ctz(x)
#define par(x) __bultin_parity(x)
#define all(x) (x).begin(), (x).end()
/* **************************************************************************************** */
const ll MOD= 1e9 + 7;
ll power_modm(ll x, ll y)  
{  
    ll res = 1;
    x = x % MOD; 
    if (x == 0) 
        return 0;
    while (y > 0)  
    {  
        if (y & 1)  
            res = (res * x) % MOD; 
        y = y >> 1;
        x = (x * x) % MOD;  
    }  
    return res;  
}
int fact_modm(ll n) 
{ 
    if(n == 0)
        return 1;
    if(n == 1)
        return 1;
    if (n >= MOD) 
        return 0; 
  
    ll result = 1; 
    for (ll i = 1; i <= n; i++) 
        result = (result * i) % MOD; 
  
    return result; 
} 
void test_case()
{
    ll n, ans;
    cin >> n;
    ans = power_modm(10, n) - (2 * power_modm(9, n) )% MOD + power_modm(8, n) + MOD;
    cout <<ans%MOD;
    return ;
}
int main()
{
	FAST_IO
    test_case();
	return 0;
}

