#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n;
    cin >> n;
    ll sum = 0;
    ll a = 0;
    vector<string> s(n);
    vector<ll> t(n);
    for(i = 0;i < n;++i){
        cin >> s.at(i) >> t.at(i);
        a += t.at(i);
    }
    string x;
    cin >> x;
    for(i = 0;i < n;++i){
        sum += t.at(i);
        if(s.at(i) == x) break;
    }
    cout << a - sum << endl;


    return 0;
}