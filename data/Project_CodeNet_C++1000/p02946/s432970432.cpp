#include <iostream>
#include <vector>
#include <cmath>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)

using namespace std;
typedef long long ll;

int main()
{
    ll k, x;
    vector <ll> ans(0);
    ll cnt = 0;
    cin >> k >> x;
    for (int i = x-k+1; i<x+k; i++) {
        ans.push_back(i);
    }
    for (auto p: ans) {
        cout << p << " ";
    }
    return 0;
}