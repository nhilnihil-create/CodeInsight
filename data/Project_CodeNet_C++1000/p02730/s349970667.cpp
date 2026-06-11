//
#include <vector>
#include <set>
#include <array>
#include <iostream>
#include <cstdio>
#include <cstdint>
//
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
void yes(bool cond) { cond ? puts("Yes") : puts("No"); }
//
ll sum(ll n) { return n * (n + 1) / 2; }
//
int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll N = S.size();
    rep(i, N / 2)
    {
        bool b0 = (S[i] == S[(N - 1) / 2 - 1 - i]);
        bool b1 = S[i] == S[((N + 3) / 2 - 1 + i)];
        bool b2 = S[i] == S[(N - 1 - i)];
        if (!b0 || !b1 || !b2)
        {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}