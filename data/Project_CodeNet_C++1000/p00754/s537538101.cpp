#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for(int i=0; i<(n); ++i)

bool isBalancedS(const string &s) {
    int cnt = 0;
    rep(i, s.size()) {
        if(s[i] == '[') cnt++;
        if(s[i] == ']') cnt--;
        if(cnt < 0) return false;
    }
    if(cnt > 0) return false;
    return true;
}
bool isBalancedR(const string &s) {
    int cnt = 0;
    rep(i, s.size()) {
        if(s[i] == '(') cnt++;
        if(s[i] == ')') cnt--;
        if(cnt < 0) return false;
    }
    if(cnt > 0) return false;
    return true;
}

bool isBalanced(const string &s) {
    if(!isBalancedS(s)) return false;
    if(!isBalancedR(s)) return false;
    // check substring
    for(int i=0; i<s.size(); ++i) {
        if(s[i] == '(') {
            int len = 0;
            int cnt = 1;
            for(int j=i+1; j<s.size(); ++j, ++len) {
                if(s[j] == '(') cnt++;
                if(s[j] == ')') cnt--;
                if(cnt==0) break;
            }
            if(!isBalancedS(s.substr(i+1, len))) return false;
        } else if(s[i] == '[') {
            int len = 0;
            int cnt = 1;
            for(int j=i+1; j<s.size(); ++j, len++) {
                if(s[j] == '[') cnt++;
                if(s[j] == ']') cnt--;
                if(cnt==0) break;
            }
            if(!isBalancedR(s.substr(i+1, len))) return false;
        }
    }
    return true;
}

int main(void){
    string s;
    while(getline(cin, s) && s!=".") {
        if(isBalanced(s)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
