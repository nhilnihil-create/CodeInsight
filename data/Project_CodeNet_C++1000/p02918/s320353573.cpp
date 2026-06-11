#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n,k;string s;
    cin >> n >> k >> s;
    int score = 0;
    rep(i,n-1) if(s.at(i) == s.at(i+1)) score++;
    int ans = min(score+2*k,n-1);
    cout << ans << endl; 
}