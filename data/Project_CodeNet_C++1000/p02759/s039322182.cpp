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
    ll N;
    cin >> N;
    printf("%lld",(N+1)/2);
}