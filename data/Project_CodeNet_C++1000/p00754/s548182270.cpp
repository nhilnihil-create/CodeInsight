#include<bits/stdc++.h>
using namespace std;

#define int long long

char* Solve(string S)
{
    stack<char> s;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == '(') s.push(')');
        else if (S[i] == '[') s.push(']');
        else if (S[i] == ')' || S[i] == ']')
        {
            if (s.empty() || s.top() != S[i]) return "no";
            s.pop();
        }
    }
    if (!s.empty()) return "no";
    return "yes";
}

signed main()
{
    string S;
    while (getline(cin, S), S != ".")
    {
        printf("%s\n", Solve(S));
    }
    return 0;
}