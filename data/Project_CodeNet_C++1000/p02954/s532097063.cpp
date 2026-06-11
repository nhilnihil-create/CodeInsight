#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


int main() {

    string s; cin >> s;
    pair<char,ll> mem;
    vector<ll> d(s.length(),0);
    mem = make_pair('R',0);
    vector<ll> ans(s.length(),0);

    rep(i,s.length()){
        if(mem.first != s[i]){
            if(mem.first == 'R') {
                for (int j = mem.second; j < i; j++) {
                    d[j] = i - j;
                }
                mem = make_pair('L',i);
            }  else if(mem.first == 'L'){
                 for (int j = mem.second; j < i; j ++){
                     d[j] = j - mem.second +1;
                 }
                 mem = make_pair('R',i);
            }
        }
    }

    for(int i = s.length() - 2; i >= 0; i --){
        if(s[i] == 'R'){
            for(int j = s.length()-1; j >= mem.second ; j --) {
                d[j] = j - i;
            }
            break;
        }
    }

    rep(i,s.length()){
        if(s[i] == 'R'){
            if(d[i]%2 == 0) ans[i+d[i]] ++;
            else ans[i+d[i]-1] ++;
        }else{
            if(d[i]%2 == 0) ans[i-d[i]] ++;
            else ans[i-d[i]+1] ++;
        }
    }

    rep(i,s.length()) cout << ans[i] << " ";

    


    


    

    return 0;
}
