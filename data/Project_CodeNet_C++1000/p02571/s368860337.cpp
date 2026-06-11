#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using ll = long long;
using pint = pair<int, int>; 
using pll  = pair<ll, ll>;
using vint = vector<int>; 
using vll  = vector<ll>;
using vstr = vector<string>;

//　定数, 変数 *********************************************
const ll MOD=1e9+7;
const ll INF=1ll<<60;

string S,T;

// *********************************************************
int main(){

    cin >>  S>> T  ;

    int ans = 1000;

    for(int i=0, len=S.length()-T.length(); i<=len; ++i){
        int k=0;
        for(int j=0, lenT=T.length(); j<lenT; ++j){
            if(S.at(i+j) != T.at(j)) ++k;
        }

        ans = min(ans,k);

    }

    cout << ans<<endl;

    return 0;
}