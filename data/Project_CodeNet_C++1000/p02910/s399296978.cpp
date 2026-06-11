#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

int main()
{
    Hello
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if((i % 2 == 0 && (s[i] == 'R' || s[i] == 'U' || s[i] == 'D' )) ||
            (i % 2 == 1 && (s[i] == 'L' || s[i] == 'U' || s[i] == 'D' )))
            continue;
        else
            return cout << "No", 0;
    }
    cout << "Yes";
    return 0;
}
