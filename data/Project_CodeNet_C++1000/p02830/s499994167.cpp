#pragma GCC optimize ("O3")
#pragma GCC target ("sse4") // wonderful

#include <bits/stdc++.h>
using namespace std;






int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;


    string res = "";
    int i = 0;
    while (n--) {
    	res += s1[i];
    	res += s2[i];
    	i++;
    }

    cout << res;
    return 0;
}
