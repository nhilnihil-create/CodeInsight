#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;

int main(){
    string s;
    ll k;
    cin >> s >> k;
    ll ans = 0;
    vector<ll> c;
    char now ;
    rep(i,s.size()){
        if(now == s[i]) c.back() ++;
        else{
            c.push_back(1);
            now = s[i];
        }
    }
    if(c.size() == 1){
        cout << (c[0] * k) /2 << endl;
        return 0;
    }
    rep(i,c.size()){
        ans += c[i] / 2;
        //cout << c[i] << " " ;
    }
    //cout << ans << endl;
    if(s.front() == s.back()){
        if(c.back() == 1 && c.front() == 1){
            cout << ans * k + k - 1 << endl;
        }else if(c.back() == 1){
            if(c.front()%2 == 0) cout << ans * k << endl;
            else cout << ans * k + k - 1 << endl;
        }else if(c.front() == 1){
            if(c.back()%2 == 0) cout << ans * k << endl;
            else cout << ans * k + k - 1 << endl;
        }else{
            if(c.back()%2 == 1 && c.front()%2 == 1) cout << ans * k + k-1 << endl;
            else cout << ans * k << endl;
        }
    }else{
        cout << ans * k << endl;
    }
    return 0;
}