#pragma GCC optimize ("O3")
#pragma GCC target ("sse4") // wonderful

#include <bits/stdc++.h>
using namespace std;






int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);


    float d, t, s;
    cin >> d >> t >> s;

    if (d/s <= t) cout << "Yes";
    else cout << "No";

    return 0;


}
