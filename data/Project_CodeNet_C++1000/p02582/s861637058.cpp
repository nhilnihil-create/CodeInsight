#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main(void){

    string s;
    cin >> s;
    int ans;
    if(s == "RRR") ans=3;
    else if(s == "RRS" || s == "SRR") ans=2;
    else if(s == "SSS") ans=0;
    else ans=1;

    cout << ans << endl;

    return 0;
}