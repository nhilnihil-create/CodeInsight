#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int score = 0;
    rep(i,s.size()) {
        if(s[i] == s[i+1]) {
            score++;
        }
    }
    int ans = min(n-1,score+2*k);
    cout << ans << endl;
}