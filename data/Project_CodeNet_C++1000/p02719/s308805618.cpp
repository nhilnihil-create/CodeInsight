// https://atcoder.jp/contests/abc161/tasks/abc161_c

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    n %= k;
    cout << min(n, k - n) << endl;
}