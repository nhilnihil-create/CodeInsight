#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define REP(i,n) for (int i=1;i<=(n);i++)
typedef long long ll;

int main() {
    string s;
    cin >> s;
    int ans = 0;
    if(s=="RRR") ans = 3;
    else if(s=="RRS") ans = 2;
    else if(s=="RSR") ans = 1;
    else if(s=="RSS") ans = 1;
    else if(s=="SRR") ans = 2;
    else if(s=="SRS") ans = 1;
    else if(s=="SSR") ans = 1;
    else if(s=="SSS") ans = 0;
    cout << ans << endl;
}