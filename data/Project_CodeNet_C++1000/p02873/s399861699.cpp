#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using vi = vector<ll>;

int main(){
    string s;
    cin >> s;
    int slen = s.length();
    vi cnt(slen+1,0);
    rep(i,slen){
        if(s[i] == '<')cnt[i+1] = max(cnt[i]+1,cnt[i+1]);
    }

    for(int i = slen-1; i >= 0 ; i--){
        if(s[i] == '>') cnt[i] = max(cnt[i+1]+1,cnt[i]); 
    }

    // rep(i,slen+1){
    //     cout << cnt[i] << " " ;
    // }
    // cout << endl;
    ll ans = 0;
    rep(i,slen+1){
        ans += cnt[i];
    }
    cout << ans << endl;
    return 0;
}
