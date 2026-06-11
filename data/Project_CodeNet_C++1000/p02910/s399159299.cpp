#include <bits/stdc++.h>
using namespace std;
int main()
{
    string S;
    cin >> S;
    string odd = "RUD";
    string even = "LUD";
    bool is_good = true;
    for (int i = 0; i < S.size(); i++)
    {
        if ((i + 1) % 2 == 1 && odd.find(S[i]) != string::npos)
        {
            continue;
        }
        else if ((i + 1) % 2 == 0 && even.find(S[i]) != string::npos)
        {
            continue;
        }
        else
        {
            is_good = false;
        }
    }
    if (is_good)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}