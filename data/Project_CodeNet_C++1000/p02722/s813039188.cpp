#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
#include <bitset>
#include <functional>
#include <numeric>
#include <ctime>
#include <cassert>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

#define FOR(i, a, b) for(int (i)=(a);(i)<(b);(i)++)
#define IFOR(i, a, b) for(int (i)=(a);(i)<=(b);(i)++)
#define RFOR(i, a, b) for(int (i)=(a);(i)>=(b);(i)--)
#define REP(i, n) FOR((i), 0, (n))

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<class T>
void print_container(T &container, string delim=" ") {
    bool first = true;
    for(auto &t: container){
        if(!first){
            cout << delim;
        }
        first = false;
        cout << t;
    }
    cout << endl;
}

vector<ll> get_divisor(ll x){
    vector<ll> ans;
    for(ll i = 1; i * i <= x; i++){
        if(x % i == 0){
            ans.push_back(i);
            if(i * i != x)
                ans.push_back(x/i);
        }
    }

    return ans;
}

ll power(int n, int p)
{
    if (p == 0)
        return 1;
    long long res = 1;
    long long add = n;
    while (p > 0)
    {
        if (p & 1)
            res = (res * add);
        p >>= 1;
        add = add*add;
    }
    return res;
}

      
int main() {
    ll n;
    cin >> n;

    ll ans = 0;
    auto d1 = get_divisor(n-1);
    ans += d1.size() - 1;
    auto d2 = get_divisor(n);
    for(auto d: d2){
        ll tmp = n / d;
        if(tmp % d == 1)
            ans++;
    }

    IFOR(i, 2, 40){
        for(ll j = 1;j<=1000000;j++){
            ll p = power(j, i);
            if(p > n) break;
            if(n % p > 0) continue;
            if((n/p)%j == 1)
                ans++;
        }
    }

    cout << ans << endl;

    
    return 0;
}