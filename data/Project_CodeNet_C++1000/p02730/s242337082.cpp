#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin >> s;

    for(int i = 1; i <= s.size(); i++)
    {
        if(s[i - 1] != s[s.size() - i])
        {
            cout << "No";
            return 0;
        }
    }
    for(int i = 1; i <= (s.size()- 1) / 2; i++)
    {
        if(s[i - 1] != s[(s.size()- 1) / 2 - i])
        {
            cout << "No";
            return 0;
        }
    }
    for(int i = (s.size() + 3) / 2; i <= s.size(); i++)
    {
        if(s[i - 1] != s[s.size() - i + (s.size() + 3) / 2 - 1])
        {
            cout << i << " " << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}