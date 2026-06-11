#pragma GCC optimize ("O3")
#pragma GCC target ("sse4") // wonderful

#include <bits/stdc++.h>
using namespace std;






int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;
    int res = 0;

    for (int i = 0; i < 3; i++) {
    	if (s1[i] == s2[i]) res++;
    }

    cout << res;

    return 0;
}
