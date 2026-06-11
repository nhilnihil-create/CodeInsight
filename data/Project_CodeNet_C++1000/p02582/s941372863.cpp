#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ans=0;
    string s;

    cin >> s;
    
    if( s == "RSS" || s == "SRS" || s =="SSR" || s == "RSR")
        ans = 1;
    else if(s == "RRS" || s =="SRR" )
        ans = 2;
    else if(s =="RRR")
        ans = 3;

    cout << ans << endl;

    return 0;
}
