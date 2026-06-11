#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string s;
int main()
{
    
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;

    if (s[2] == s[3] && s[4] == s[5]){
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    
 
    return 0;
}