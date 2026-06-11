#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
#define MOD 1000000007
int main()
{
    ll N, K;
    cin >> N >> K;
    ll sum = 0;
 
    for (ll i = K; i <= N + 1; i++)
    {
        ll low = (i - 1) * i / 2;
        ll high = (2 * N + 1 - i) * i / 2;
        ll add = high - low + 1;
        sum = (sum + add) % MOD;
    }
 
    cout << sum << endl;

    return 0;
}