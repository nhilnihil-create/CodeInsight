#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

template<typename T>
istream& operator>> (istream& is, vector<T> &vec){
    for(T& x: vec) is >> x;
    return is;
}

int main(){
    ll x; cin >> x;
    vector<vector<string>> l(10, vector<string>());
    vector<string> lm;
    rep(i, 9){
        l[0].push_back(string(1, (i+1)+'0'));
        lm.push_back(l[0][i]);
    }
    ll cnt = 9;
    for(ll i = 1; i < 10; ++i){
        for(auto v : l[i-1]){
            ll last = v[v.length()-1] - '0';
            for(ll j = -1; j < 2; ++j){
                string tmp = v;
                if(0 <= last+j && last+j <= 9){
                    tmp += (last+j) + '0';
                    l[i].push_back(tmp);
                    lm.push_back(tmp);
                    cnt++;
                }
            }
            if(cnt >= 100000) break;
        }
        if(cnt >= 100000) break;
    }

    cout << lm[x-1] << endl;
    return 0;
}