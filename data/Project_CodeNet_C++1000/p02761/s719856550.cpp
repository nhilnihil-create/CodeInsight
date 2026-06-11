#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
int main()
{
    int n, m;
    cin >> n >> m;
    string ans = "0";
    if(n==3) ans = "100";
    if(n==2) ans = "10";
    int s;
    char c;
    vector<char> cnt(n, 'F');
    rep(i, m){
        cin >> s  >> c;
        s--;
        if(cnt[s] != c && cnt[s]!='F') {ans = "-1"; break;}
        else{cnt[s] = c;}
        if(s==0 && n>=2 && c=='0') {ans = "-1"; break;}
        ans[s] = c;
    }

    cout << ans << endl;

    return 0;
}