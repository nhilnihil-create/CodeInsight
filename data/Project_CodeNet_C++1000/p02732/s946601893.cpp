#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
#define MOD 1000000007
int main()
{   
    int n;
    ll a[200005] = {}, c[200005] = {}, z = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], c[a[i]]++;
    for (int i = 1; i <= n; i++) z += c[i] * (c[i] - 1) / 2;
    for (int i = 1; i <= n; i++) cout << z - c[a[i]] + 1 << '\n';
    return 0;
}