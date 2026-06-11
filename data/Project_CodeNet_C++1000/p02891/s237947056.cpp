#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<char,int> PCI; 
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

vector<pair<char, int>> lanl(string s){
    int n = s.size();
    vector<pair<char, int>> res;
    res.push_back({s[0], 1});
    for(int i=1; i<n; i++){
        if(s[i] == res.back().first){
            ++res.back().second;
        }else{
            res.push_back({s[i], 1});
        }
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;cin>>s;
    int n = s.size();
    ll k; cin>>k;
    if(s == string(n, s[0])){
        cout<<n*k/2<<endl;
        return 0;
    }
    vector<PCI> t = lanl(s);
    ll p = 0;
    for(auto a : t){
        p += a.second/2;
    }
    ll ans = p*k;
    if(t.front().first == t.back().first){
        ll a = t.front().second;
        ll b = t.back().second;
        ans = ans - (a/2 + b/2 - (a+b)/2) * (k-1);
    }
    cout<<ans<<endl;
}