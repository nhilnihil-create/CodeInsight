#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string s, t;
    cin >> s >> t;

    for(int i = 0; i < s.length(); i++)
        if(s[i] != t[i]){
            cout << "No\n";
            return 0;
        }

    cout << "Yes\n";
    return 0;
}
