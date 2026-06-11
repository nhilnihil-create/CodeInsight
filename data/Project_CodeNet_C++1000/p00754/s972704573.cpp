#include <bits/stdc++.h>

using namespace std;

bool balanced(string s)
{
    deque<char> deq;
    for(string::iterator itr = s.begin(); itr!=s.end(); itr++)
    {
        switch(*itr)
        {
            case '(':
                deq.push_back(')');
                break;
            case '[':
                deq.push_back(']');
                break;
            case ')':
            case ']':
                if(deq.empty() || deq.back() != *itr) return false;
                deq.pop_back();
                break;
        }
    }
    return deq.empty();
}

int main()
{
    string s;
    while(getline(cin, s), s!=".")
    {
        cout << (balanced(s) ? "yes" : "no") << endl;
    }
}