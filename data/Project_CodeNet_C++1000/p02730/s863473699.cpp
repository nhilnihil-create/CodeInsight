#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

bool is_kaibun(string s)
{
    bool a = true;
    for (int i = 0; i < s.size() / 2; i++)
    {
        if (s.at(i) != s.at(s.size() - 1 - i))
        {
            a = false;
        }
    }
    return a;
}

int main()
{
    string s;
    cin >> s;

    bool flag = true;

    string s1, s2;
    s1 = "";
    s2 = "";

    for (int i = 0; i < (s.size()-1) / 2; i++)
    {
        s1 += s.at(i);
    }
    for (int i = (s.size()+2) / 2; i < s.size(); i++)
    {
        s2 += s.at(i);
    }

    if (is_kaibun(s) && is_kaibun(s1) && is_kaibun(s2))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}