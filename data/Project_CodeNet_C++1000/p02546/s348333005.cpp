//in the name of god
#include <bits/stdc++.h>

using namespace std;

string s;

int main()
{
    cin >> s;
    if(s[s.size() - 1] != 's')
    {
        s += 's';
    }

    else
    {
        s += "es";
    }

    cout << s << '\n';    
}