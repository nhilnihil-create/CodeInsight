#pragma GCC optimize ("O3")
#pragma GCC target ("sse4") // wonderful

#include <bits/stdc++.h>
using namespace std;






int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    int a; cin >> a;
    string s; cin >> s;

    if (a < 3200) cout << "red";
    else cout << s;




    return 0;
}
