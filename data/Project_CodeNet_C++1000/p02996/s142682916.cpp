#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int n;
    cin >> n;
    vector<pair<ll, ll>> p(n);
    rep(i,n){
        cin >> p[i].second >> p[i].first;
    }
    sort(p.begin(),p.end());
    ll time = 0;
    rep(i,n){
        time += p[i].second;
        if(time > p[i].first){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}