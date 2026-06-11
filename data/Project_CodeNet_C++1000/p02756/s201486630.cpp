#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vl = vector<ll>; using vvl = vector<vl>;
using vp = vector<pair<int,int>>;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
const ll INF = 9223372036854775807;

int main(){
    string s;cin >> s;
    int n;cin >> n;
    deque<char> ans;
    rep(i,s.size()) ans.push_back(s[i]);
    bool TF = true;
    rep(i,n){
        int a;cin >> a;
        if(a == 1){
            if(TF) TF = false;
            else if(!TF) TF = true;
        }
        if(a == 2){
            int b;cin >> b;
            char c;cin >> c;
            if(b == 1){
                if(TF) ans.push_front(c);
                if(!TF) ans.push_back(c);
            }
            if(b == 2){
                if(TF) ans.push_back(c);
                if(!TF) ans.push_front(c);
            }
        }
    }
    string Ans = "";
    if(!TF) reverse(ans.begin(),ans.end());
    rep(i,ans.size()) Ans += ans[i];
    cout << Ans << endl;
}
