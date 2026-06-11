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
    ll N;
    cin >> N;
    ll s = sum(N) - sum(N / 3) * 3 - sum(N / 5) * 5 + sum(N / 15) * 15;
    printf("%lld", s);
}