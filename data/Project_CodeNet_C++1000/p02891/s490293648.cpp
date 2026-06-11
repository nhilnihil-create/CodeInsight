#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi=vector<int>;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    ll k;
    cin >> s >> k;
    ll n = s.size();

    s += s;
    ll a=0,b=0;
    bool all_same = false;
    rep(i,n-1){
        if(s[i]!=s[i+1]){
            all_same = true;
            break;
        }
    }
    rep(i,n-1){
        if(s[i]==s[i+1]){
            a++;
            s[i+1] = '#';
        }
    }

    for(int i=n-1;i<2*n-1;i++){
        if(s[i]==s[i+1]){
            b++;
            s[i+1] = '#';
        }
    }
    if(all_same) cout << a+b*(k-1) << "\n";
    else cout << n*k/2 << "\n";
    return 0;
}
