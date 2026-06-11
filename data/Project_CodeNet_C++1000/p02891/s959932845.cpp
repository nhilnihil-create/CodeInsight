#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
ll res(string s){
    ll ans = 0;
    for(ll i = 0; i < s.size();){
         ll cnt = 0;
        while(s[i] == s[i+cnt+1]){
            cnt++;
        }
        ans += (cnt+1)/2;
        i += cnt+1;
    }
    return ans;
}
int main(){
    cout << fixed << setprecision(10);

    string s;
    cin >> s;
    ll k;
    cin >> k;
    map<char,int> mci;
    for(auto u : s){
        mci[u]++;
    }
    if(mci.size() == 1){
        cout << s.size()*k/2 << endl;
        return 0;
    }
    if(s[0] != s[s.size()-1]){
        cout << res(s)*k << endl;
        return 0;
    }
    ll sub = res(s+s) - res(s);
    //cout << res(s) << endl;
    //cout << sub << endl;
    cout << res(s) + sub*(k-1) << endl;
    return 0;
}