#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

//pdf見て解答
//自力で思いつく気がしない

int main(){
    string s; cin >> s;
    
    vector<ll> cnt(s.size()+1,0);
    ll ans = 0;

    for(int i = 1; i <= s.size(); i++){
        if(s[i-1] == '<') cnt[i] = cnt[i-1] + 1;
    }
    for(int i = s.size()-1; i >= 0; i--){
        if(s[i] == '>') cnt[i] = max(cnt[i], cnt[i+1] + 1);
    }

    //for(auto x:cnt) cout << x << " "; cout << endl;

    put(accumulate(cnt.begin(),cnt.end(),0LL));
}