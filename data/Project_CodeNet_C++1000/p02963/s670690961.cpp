#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 1000000007;
using ll = long long;
int main() {
ll s;
cin >> s;
ll x=(1000000000LL-s%1000000000LL)%1000000000LL;
ll y=(s+x)/1000000000LL;

cout << "0 0 1000000000 1 " << x <<" "<< y << endl;
}
