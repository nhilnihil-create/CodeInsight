#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n-1; i >= 0; i--)
#define PRINT(x) cout << x << endl

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll MOD = 1000000007;


int main()
{
    ll N;
    cin >> N;
    map<ll, ll> m;
    REP(i, N) {
        ll a;
        cin >> a;
        m[a]++;
    }
    bool flag = m.size() == 1 && m[0] == N;
    flag |= m.size() == 2 && N % 3 == 0 && m[0] == N/3;
    ll sum = 0;
    bool flag2 = true;
    for(P t : m) {
        sum ^= t.first;
        flag2 &= t.second == N / 3;
    }
    flag |= m.size() == 3 && N % 3 == 0 && sum == 0 && flag2;
    if (flag) {
        PRINT("Yes");
    } else {
        PRINT("No");
    }
    return 0;
}
