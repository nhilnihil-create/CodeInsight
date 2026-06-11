#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    string s;
    cin >> s;
    ll n = s.size();
    vector<pair<ll,ll>> a;
    char tmp = s.at(0);
    ll num = 1;
    for(i = 1;i < n;++i){
        if(s.at(i) == tmp) ++num;
        else{
            if(tmp == '<'){
                a.emplace_back(num, 1);
            }else{
                a.emplace_back(num, -1);
            }
            tmp = s.at(i);
            num = 1;
        }
    }
    if(tmp == '<'){
        a.emplace_back(num, 1);
    }else{
        a.emplace_back(num, -1);
    }
    ll ans = 0;
    vector<ll> b;
    if(a.size() == 1){
        cout << a.at(0).first*(a.at(0).first+1)/2 << endl;
        return 0;
    }
    for(i = 0;i + 1 < a.size();i += 2){
        if(i == 0 && a.at(i).second == -1){
            b.push_back(a.at(i).first);
            --i;
        }else{
            ll t = max(a.at(i).first, a.at(i+1).first);
            ll s = min(a.at(i).first, a.at(i+1).first);
            b.push_back(t);
            b.push_back(s-1);
        }
    }
    if(a.back().second == 1){
        b.push_back(a.back().first);
    }
    for(i = 0;i < b.size();++i){
        ans += (b.at(i)+1)*b.at(i)/2;
    }
    cout << ans << endl;

    return 0;
}