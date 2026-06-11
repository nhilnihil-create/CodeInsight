#pragma GCC optimize ("O3")
#pragma GCC target ("sse4") // wonderful

#include <bits/stdc++.h>
using namespace std;






int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);


    int total, max, time;
    cin >> total >> max >> time;

    int res = 0;

    while (total > 0) {
    	res += time; 
    	total -= max;
    }


    cout << res;

    return 0;


}
