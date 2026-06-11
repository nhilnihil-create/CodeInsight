#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;
    ll k;
    cin >> k;
    set<char> st;
    for(char c : s) st.insert(c);
    if(st.size()==1){
        cout << k*s.size()/2 << endl;
        return 0;
    } 
    ll a = 0;
    string t = s;
    for(int i = 1; i < t.size(); ++i) {
        if(t[i]==t[i-1]){
            a++;
            t[i]='#';
        }
    }
    ll b = 0;
    s+=s;
    for(int i = 1; i < s.size(); ++i){
        if(s[i]==s[i-1]){
            b++;
            s[i]='#';
        }
    }
    b-=a;
    cout << (k-1)*b + a << endl;
    return 0;
}