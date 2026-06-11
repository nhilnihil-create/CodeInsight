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
    string S;
    cin >> S;
    string pre = "";
    ll cnt = 0;
    ll left = 0;
    REP(i, S.length()) {
        if (S.substr(left, i+1 - left) != pre) {
            pre = S.substr(left, i+1 - left);
            left = i+1;
            cnt++;
        }
    }
    PRINT(cnt);
    return 0;
}
