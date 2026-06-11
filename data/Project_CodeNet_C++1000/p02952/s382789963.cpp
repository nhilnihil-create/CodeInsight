#pragma GCC optimize ("O3")
#pragma GCC target ("sse4") // wonderful

#include <bits/stdc++.h>
using namespace std;






int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);


    int x; cin >> x;

    int res = 0;

    for (int i = 1; i < 10 && i <= x; i++) res++;
    for (int i = 100; i < 1000 && i <= x; i++) res++;
    for (int i = 10000; i < 100000 && i <= x; i++) res++;
    cout << res;




    return 0;
}
