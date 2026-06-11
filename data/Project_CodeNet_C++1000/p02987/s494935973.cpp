#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;
    string ans = "Yes";
    sort(ALL(s));
    if(s[1]== s[2] || s[0] != s[1] || s[2] != s[3]) ans = "No";
    cout << ans << endl;
    return 0;
}