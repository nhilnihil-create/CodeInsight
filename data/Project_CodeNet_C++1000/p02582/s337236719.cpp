#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string s;
    int count = 0;
    cin >> s;

    if(s[0] == 'R' ||
       s[1] == 'R' ||
       s[2] == 'R'
    )
        count = 1;


    if(s[0] == 'R' &&
       s[1] == 'R'
       ||
       s[1] == 'R' &&
       s[2] == 'R'
    )
        count = 2;

    if(s[0] == 'R' &&
       s[1] == 'R' &&
       s[2] == 'R'
    )
        count = 3;
    
    cout << count << endl;

}