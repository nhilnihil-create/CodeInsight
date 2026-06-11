#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N;
    string s;
    cin >> N >> s;
    bool is = true;
    rep(i, N-1) if(s[i] != s[i+1]) is = false;
    if(is){
        cout << 1 << endl;
        return 0;
    }
    int ans = 0;
    rep(i, N){
        if(s[i] == s[i+1]){
            while(s[i] == s[i+1] && i < N) i++;
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}