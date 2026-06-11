#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const ll INF = 1LL << 60;
ll mod_pow(ll, ll, ll); ll mod_fact(ll, ll); ll mod_inv(ll, ll); ll gcd(ll, ll); ll lcm(ll, ll);
//
int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    for(int i = 0; i < n; i++){
        int x, l;
        cin >> x >> l;
        a.emplace_back(x + l, x - l);
    }
    sort(a.begin(), a.end());
    int cnt = 0;
    int coo = INT_MIN;
    for(int i = 0; i < n; i++){
        auto p = a[i];
        if(coo <= p.second){
            coo = p.first;
            cnt++;
        }
    }
    cout << cnt;
}