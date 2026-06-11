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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int main(){
    cout << fixed << setprecision(10);
    string s;
    cin >> s;
    vector<pair<int,int>> v;
    int pre;
    int now = 0;
    rep(i, s.size()){
        if(i == 0){
            if(s[i] == '<'){
                pre = 1;
                now++;
                if(i == s.size()-1) v.push_back({pre,now});
            }else{
                pre = 0;
                now++;
                if(i == s.size()-1) v.push_back({pre,now});
            }
        }else{
            if(s[i] == '<'){
                bool push = 0;
                if(pre == 1){
                    now++;
                    if(i == s.size()-1) v.push_back({pre,now});
                }else{
                    push = 1;
                    v.push_back({pre,now});
                    pre = 1;
                    now = 1;
                    if(i == s.size()-1){
                        v.push_back({pre,now});
                    }
                }
            }else{
                if(pre == 0){
                    now++;
                    if(i == s.size()-1) v.push_back({pre,now});
                }else{
                    v.push_back({pre,now});
                    pre = 0;
                    now = 1;
                    if(i == s.size()-1){
                        v.push_back({pre,now});
                    }
                }
            }
        }
    }

    ll ans = 0;

    rep(i, v.size()){
        if(i == 0){
            rep(j,v[i].second+1){
                ans += j;
            }
            if(v[i].first == 1){
                if(v.size() != 1) ans -= min(v[i].second, v[i+1].second);
            }
        }else if(i == v.size()-1){
            rep(j,v[i].second+1){
                ans += j;
            }
        }else{
            rep(j,v[i].second+1){
                ans += j;
            }
            if(v[i].first == 1){
               ans -= min(v[i].second, v[i+1].second);
            }
        }
    }
    cout << ans << endl;
    return 0;
}