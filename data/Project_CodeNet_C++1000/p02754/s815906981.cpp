//
#include <vector>
#include <set>
#include <array>
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <numeric>
#include <bitset>

//
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
void yes(bool cond) { cond ? puts("Yes") : puts("No"); }
//
int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    ll N, A, B;
    cin >> N >> A >> B;
    cout << (N / (A + B)) * A + min((N % (A + B)), A);
}