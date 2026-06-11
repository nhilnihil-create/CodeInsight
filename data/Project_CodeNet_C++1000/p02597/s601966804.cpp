#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
typedef long long ll;


int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int r = 0;
    int now = 0;
    rep(i,n) if(s[i]=='R') r++;
    rep(i,r) if(s[i]=='R') now++;
    cout << r-now << endl;
    return 0;
}