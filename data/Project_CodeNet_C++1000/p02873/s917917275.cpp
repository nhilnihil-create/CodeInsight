#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    ll n = s.size() + 1;
    vector<P> cnt;
    int l = 0;
    int r = 0;
    for(char c : s){
        if(c == '<'){
            if(r != 0){
                cnt.push_back(make_pair(l, r));
                l = 0;
                r = 0;
            }
            l++;
        }else{
            r++;
        }
    }
    if(l != 0 || r != 0)cnt.push_back(make_pair(l, r));
    ll ans = 0;
    for(P p : cnt){
        ll a = p.first;
        ll b = p.second;
        if(a < b)swap(a, b);
        ans += a * (a + 1) / 2 + b * (b - 1) / 2;
    }
    cout << ans << endl;
}