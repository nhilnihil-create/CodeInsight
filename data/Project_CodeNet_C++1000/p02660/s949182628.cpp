#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<set>
#include<map>
#include<bitset>
#include<iomanip>
#include<stack>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll mod = 1000000007;

vector<P> prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0;
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        res.push_back({ a, ex });
    }
    if (N != 1) res.push_back({ N, 1 });
    return res;
}

int main() {
	ll n;
	cin >> n;
    vector<P> p;
    p = prime_factorize(n);
    ll count = 0;
    for (auto id: p) {
        ll index = 1;
        while (id.second > 0) {
            if (id.second - index < 0) {
                break;
            }
            id.second -= index;
            index++;
            count++;
        }
    }
    cout << count << endl;
    return 0;
}