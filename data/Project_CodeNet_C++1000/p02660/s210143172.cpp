/* Start coding only after you have clear idea.*/
#pragma GCC optimize(2)
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <iomanip>
#include <set>
using namespace std;
typedef long long ll;
const int N = 1e6 + 11;
#define inf 2000000007
#define mod 1000000007
#define IosF ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int prime[N/3];
int miniFactor[N];
int primepos = 0;
void euler()
{
    int tmp;
    for (int i = 2; i < N; i++)
    {
        if (!miniFactor[i]) prime[primepos++] = i, miniFactor[i] = i;
        for (int j = 0; (tmp = i*prime[j]) < N && j<primepos; j++)
        {
            miniFactor[tmp] = prime[j];
            if (!(i % prime[j])) break;
        }
    }
}

vector<ll> Q;
int main() {
    IosF;
    euler();
    ll n, k;
    cin >> n;
    for ( int i = 0; i < primepos; ++ i ) {
        k = 1ll * prime[i];
        while ( k <= n ) {
            Q.push_back(k);
            k *= 1ll * prime[i];
        }
    }
    sort(Q.begin(), Q.end());
    int len = Q.size(), res = 0;
//    cout << len << endl;
    k = n;
    for ( int i = 0; i < len; ++ i ) {
        if ( k % Q[i] ) continue;
        if ( k < Q[i] ) break;
        k /= Q[i];
        ++ res;
    }
    for ( int i = 0; i < primepos; ++ i ) {
        while ( !(n % prime[i]) ) n /= prime[i];
    }
    if ( n > 1 ) ++ res;
    cout << res << endl;
    return 0;
}
