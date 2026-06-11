#pragma GCC optimize ("O3")
#pragma GCC target ("sse4") // wonderful

#include <bits/stdc++.h>
using namespace std;






int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    
    string s; cin >> s;

    for (int i = 0; i < s.size(); i++)
    	s[i] = 'x';

    cout << s;

    return 0;
}
