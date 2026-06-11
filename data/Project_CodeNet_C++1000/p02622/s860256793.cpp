#include <bits/stdc++.h>

using namespace std;

int main()
{

    string s, t;
    int c = 0;

    cin >> s >> t;

    int x = s.length();

    for (size_t i = 0; i < x; i++)
    {
        if(s[i] != t[i])
        {
            c++;
        }
    }
    
    cout << c;


    return 0;
}