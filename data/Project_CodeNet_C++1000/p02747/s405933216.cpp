#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
using namespace std;

void solve() {
    string s; cin >> s;
    int f = 1;
    if(s.size()%2 != 0) f = 0;
    else{
        for(int i = 0; i < s.size(); i += 2){
            if(s[i] != 'h' || s[i+1] != 'i') f = 0;
        }
    }
    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve();
    return 0;
}
 
