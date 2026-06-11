#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int n, k;
    int score[3];
    string s;
    cin >> n >> k >> score[0] >> score[1] >> score[2] >> s;
    map<char, int> m;
    m['s'] = 0;
    m['p'] = 1;
    m['r'] = 2;
    int ans = 0;
    for( int i = 0; i < n; i++ )
    {
        if( m.count(s[i]) > 0 )
        {
            if( i < k || s[i] != s[i - k] )
            {
                ans += score[m[s[i]]];
            }
            else
            {
                s[i] = '-';
            }
//            cout << ans << endl;
        }        
    }

    cout << ans;
}