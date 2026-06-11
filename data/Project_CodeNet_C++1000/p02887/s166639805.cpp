#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N;
    string s;
    cin >> N >> s;
    s.push_back('#');
    int ans = 0;
    rep(i, N){
        if(s[i] != s[i+1]) ans++;
    }
    cout << ans << endl;
    return 0;
}