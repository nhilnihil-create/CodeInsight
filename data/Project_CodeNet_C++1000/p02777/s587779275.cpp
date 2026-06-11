#pragma GCC optimize ("O3")
#pragma GCC target ("sse4") // wonderful

#include <bits/stdc++.h>
using namespace std;






int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2, s3;
    cin >> s1 >> s2;
    int a, b;
    cin >> a >> b;
    cin >> s3;


    if (s3 == s1) {
    	cout << a-1 << " " << b;
    } else {
    	cout << a << " " << b-1;
    }

    return 0;
}
