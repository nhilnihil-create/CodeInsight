#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
#define P pair<int, int>
using namespace std;

int main(){
    string s;
    cin >> s;
    ll ans = 0;
    ll cntr = 0, cntl = 0;
    int n = s.size();
    rep(i, n){
        if(s[i] == '<')cntr++;
        if(s[i] == '>')cntl++;
        if((s[i] == '>' && s[i+1] == '<') || i == n-1){
            ll MAX = max(cntr, cntl);
            ll MIN = min(cntr, cntl);
            ans += MAX*(MAX+1)/2 + (MIN-1)*MIN/2;
            cntr = 0;
            cntl = 0;
        }
    }
    cout << ans << endl;
    return 0;
}

/*
0<3>2>1>0
0<1<2>0 
0<1<2<3<4<5>2>1>0
0<1
<>>><<><<<<<>>><<>

*/