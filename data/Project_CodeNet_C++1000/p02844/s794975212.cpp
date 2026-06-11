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
    ll n; string s;
    cin >> n >> s;
    vector<vector<ll>> cnt(11, vector<ll>(n, 0));
    for(ll i = s.length()-1; i >= 0; --i){
        rep(j, cnt.size()-1){
            if(i == s.length()-1) break;
            cnt[j][i] = cnt[j][i+1];
        }
        cnt[s[i]-'0'][i]++;
        for(ll j = 0; j < cnt.size()-1; ++j) if(cnt[j][i] > 0) cnt[10][i]++;
    }

    ll total = 0;
    for(ll i = 0; i < 10; ++i){
        size_t index1 = s.find('0'+i);
        if(index1 == string::npos) continue;
        for(ll j = 0; j < 10; ++j){
            size_t index2 = s.find('0'+j, index1+1);
            
            if(index2 != string::npos && index2+1 != s.length()){
                total += cnt[10][index2+1];
            }
        }
    }
    cout << total << endl;
    return 0;
}