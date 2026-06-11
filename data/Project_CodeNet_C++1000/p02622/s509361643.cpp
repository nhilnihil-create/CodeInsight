#include <iostream>
#include<string>
using namespace std;
int main()
{
    string s, T; int countt = 0;
    cin >> s >> T;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != T[i])
        {
            countt++;
        }
    }
    cout << countt << endl;
}