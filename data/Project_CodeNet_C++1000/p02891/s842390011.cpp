#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <random>
#include <cassert>
#include <numeric>
#define ll long long int
#define LL unsigned long long
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};
const int MOD = 1000000007;

ll y[10000005];

int main() {
    string s; cin >> s;
    ll k; cin >> k;
    vector<ll> l;

    ll cnt = 1;
    rep(i,s.size()-1){
        if(s[i]==s[i+1]) cnt++;
        else{
            l.pb(cnt);
            cnt = 1;
        }
    }l.pb(cnt);
    

    ll ans = 0,ha = 0;
    if(s[0] == s[s.size()-1] && l.size() > 2){
        ha += l[0] / 2 + l[l.size()-1] / 2;
        l[0] += l[l.size()-1];
        l[l.size()-1] = 0;
        ans += l[0]/2 * (k-1);
        ll s = 0;
        for(int i = 1; i < l.size(); i++){
            s += l[i] / 2ll;
        }
        //cout << ans << endl;
        cout << ha + ans + s * k << endl;
        return 0;
    }
    if(l.size() == 1){
        cout << l[0] * k / 2ll << endl;
        return 0;
    }

    ll n = 0;
    rep(i,l.size()){
        n += l[i] / 2ll;
    }
    cout << n * k << endl;
}
