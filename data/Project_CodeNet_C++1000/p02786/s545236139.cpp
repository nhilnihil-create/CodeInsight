#include <bits/stdc++.h>
#define ll long long
     
using namespace std;
     
int main() {
    ll n;
    cin >> n;
    queue<pair<ll, ll>> monsters;
    monsters.push({1, n});
    ll atk = 0;
    while (!monsters.empty()) {
        pair<ll, ll> hp = monsters.front();
        monsters.pop();
        atk += hp.first;
        if (hp.second / 2 > 0) {
            monsters.push({hp.first * 2, hp.second / 2});
        }
    }
    cout << atk;
}