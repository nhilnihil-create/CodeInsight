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
int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    ll N, K, d, tmp;
    cin >> N >> K;
    vector<bool> have(N, false);
    rep(ti, K)
    {
        cin >> d;
        rep(di, d)
        {
            cin >> tmp;
            have[tmp-1] = true;
        }
    }
    ll cnt = 0;
    rep(i, have.size())
    {
        cnt += !have[i];
    }
    printf("%lld",cnt);
}