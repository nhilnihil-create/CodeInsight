#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pil = pair<pii,int>;

const int INF = 2e9;

int main(){
    string s;
    cin >> s;
    int t = s.size();
    bool ok = true;
    rep(i,t){
        if(i%2 == 0){
            if(s[i] != 'R' && s[i] != 'U' && s[i] != 'D')ok = false;
        }
        else {
            if(s[i] != 'L' && s[i] != 'U' && s[i] != 'D')ok = false;
        }
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}