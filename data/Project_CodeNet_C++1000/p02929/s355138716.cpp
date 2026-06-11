#include "bits/stdc++.h"
 
typedef long long ll;
#define int ll
#define fi first
#define se second
#define SORT(a) sort(a.begin(),a.end())
#define rep(i,n) for(int i = 0;i < (n) ; i++) 
#define REP(i,n) for(int i = 0;i < (n) ; i++) 
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define INF LLONG_MAX/2
#define all(x) (x).begin(),(x).end()
#define debug(x) cerr<<#x<<": "<<x<<endl
#define debug_vec(v) cerr<<#v<<":";rep(i,v.size())cerr<<" "<<v[i];cerr<<endl
using namespace std;

// int MOD = 998244353;
int MOD = 1000000007;


signed main(){
    
    ll n;
    string s;
    cin >> n >> s;

    if(s[0] == 'W' || s[2*n-1] == 'W'){
        cout << 0 << endl;
        return 0;
    }

    vector<char> lr(2*n);
    lr[0] = 'L';
    lr[2*n-1] = 'R';

    
    for(int i = 1;i < 2*n-1;i++){
        if(s[i] == s[i-1]){
            if(lr[i-1] == 'L')lr[i] = 'R';
            else lr[i] = 'L';
        }else{
            if(lr[i-1] == 'L')lr[i] = 'L';
            else lr[i] = 'R';
        }
    }
    // rep(i,2*n)cerr << lr[i];
    // cerr << endl;
    ll x=0,y=0;
    rep(i,2*n){
        if(lr[i] == 'L')x++;
        else y++;
    }
    if(x != y){
        cout << 0 << endl;
        return 0;
    }


    if((lr[2*n-1] == lr[2*n-2]) == (s[2*n-1] == s[2*n-2])){
        cout << 0 << endl;
        return 0;
    }

    ll lc = 0;
    ll ans = 1;
    rep(i,2*n){
        if(lr[i] == 'L')lc++;
        else{
            ans *= lc;
            ans %= MOD;
            lc--;
        }
    }
    for(int i = 1;i <= n;i++){
        ans *= i;
        ans %= MOD;
    }
    cout << ans << endl;
    
    return 0;
}

// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl https://jsc2019-qual.contest.atcoder.jp/tasks/jsc2019_qual_a
// rm -r -f test;oj dl https://cf17-final-open.contest.atcoder.jp/tasks/cf17_final_a
// rm -r -f test;oj dl http://abc125.contest.atcoder.jp/tasks/abc125_a
