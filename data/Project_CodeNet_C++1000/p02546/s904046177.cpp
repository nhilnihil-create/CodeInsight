#include <bits/stdc++.h>

using namespace std;
string s;
int main ()
{
    cin >> s;
    if (s[s.size() - 1] == 's')
        return cout << s << "es", 0;
    else
        return cout << s << 's', 0;
    return 0;    
}