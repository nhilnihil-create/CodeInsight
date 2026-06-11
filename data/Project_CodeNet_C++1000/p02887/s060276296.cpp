#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    string s; cin >> s;
    int ans =0; int ch =-1;
    for (int x=0;x<n;x++){
        if ((int)s[x]==ch) continue;
        else{
            ch = (int)s[x];
            ans++;
        }
    }
    cout << ans << endl;
}
