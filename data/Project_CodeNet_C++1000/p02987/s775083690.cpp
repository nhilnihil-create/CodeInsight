#include <bits/stdc++.h>
#define io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed main(){
    io();
    string s; cin >> s;
    sort(s.begin(), s.end());
    puts(s[0] == s[1] && s[2] == s[3] && s[1] != s[2] ? "Yes":"No");
    return 0;
}