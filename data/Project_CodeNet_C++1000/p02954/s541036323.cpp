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
    string s; cin >> s;
    ll r = 0, l = 0;
    vector<pair<ll, ll>> rl; //l, r
    rep(i, s.length()){
        if(s[i] == 'R'){
            if(l > 0){
                rl.push_back(make_pair(r/2+r%2+l/2, r/2+l/2+l%2));
                l = 0;
                r = 0;
            }
            r++;
        }else{
            l++;
        }
    }
    rl.push_back(make_pair(r/2+r%2+l/2, r/2+l/2+l%2));
    for(ll i = 0, index = 0; i < s.length(); ++i){
        if(i > 0) cout << " ";
        if(s[i] == 'R' && s[i+1] == 'L'){
            cout << rl[index].first << " " << rl[index].second;
            i++; index++;
        }else{
            cout << "0";
        }
    }
    cout << endl;
    return 0;
}