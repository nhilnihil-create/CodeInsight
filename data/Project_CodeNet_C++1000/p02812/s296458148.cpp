#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}


int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for(int i = 0;i+2<s.size();i++) {
        if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C') ans++;
    }
    cout << ans << endl;
}