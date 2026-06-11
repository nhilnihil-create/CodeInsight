#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)//rep(i,回数){処理}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    int count=0;
    rep(i,n-2) {
        if ((s[i]=='A') && (s[i+1]=='B') && (s[i+2]=='C')){
            count += 1;
        }
    }
    cout << count << endl;

    return 0;
}