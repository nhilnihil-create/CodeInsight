#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    int ans = 1;
    char now = s[0];

    for(int i=1; i<n; i++){
        if(s[i] == now) continue;
        else { ans++; now = s[i];}
    }

    cout << ans << endl;
    return 0;
}