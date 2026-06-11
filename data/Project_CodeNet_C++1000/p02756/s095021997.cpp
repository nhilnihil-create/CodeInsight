#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int INF = 2e9;

int main(){
    string s;
    cin >> s;
    deque<char> ans;
    rep(i,s.size()){
        ans.push_back(s[i]);
    }
    int q;
    cin >> q;
    bool rev = false;
    rep(i,q){
        int t;
        cin >> t;
        if(t == 1){
            if(rev) rev = false;
            else rev = true;
        }
        else{
            int f;
            char c;
            cin >> f >> c;
            if(f == 1){
                if(rev) ans.push_back(c);
                else ans.push_front(c);
            }
            else{
                if(rev) ans.push_front(c);
                else ans.push_back(c);
            }
        }
    }
    int number = ans.size();
    if(rev){
        for(int i = number-1;i >= 0;i--){
            cout << ans[i];
        }
    }
    else{
        rep(i,number) cout << ans[i];
    }
}