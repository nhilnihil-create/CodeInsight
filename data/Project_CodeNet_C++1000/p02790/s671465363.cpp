#pragma GCC optimize ("O3")
#pragma GCC target ("sse4") // wonderful

#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);



    int a, b; cin >> a >> b;
    
    if (a <= b) {
        string res = "", c;
        c = to_string(a);

        while (b--) res += c;
        cout << res;
    } else {
        string res = "", c;
        c = to_string(b);

        while (a--) {
            res += c;
        }

        cout << res;
    }




    return 0;
}