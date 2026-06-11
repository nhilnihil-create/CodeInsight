#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define mat vector<vector<int>>
const int inf = 1 << 30;
const ll linf = 1e18;
const db EPS = 1e-7;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}

string s, t;
vector<int> idx[26];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> t;
    for(int i = 0; i < s.length(); ++i){
        idx[s[i] - 'a'].emplace_back(i);
    }
    int last = -1;
    ll cnt = 0;
    for(int i = 0; i < t.length(); i++){
        int al = t[i] - 'a';
        vector<int>& v = idx[al];
        auto it = upper_bound(v.begin(), v.end(), last);
        if(it != v.end()) last = *it;
        else if(v.size() == 0){
            cout << -1 << endl;
            return 0;
        }else{
            last = v[0];
            cnt++;
        }
    }
    cout << cnt * s.length() + last + 1 << endl;
    return 0;
}