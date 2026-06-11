#include <iostream>
#include <string>
using namespace std;

#define charToInt(c) (c-'0')

int main()
{
    string s;
    int sum = 0;
    cin >> s;

    for (int i=0; i<s.length(); ++i)
    {
        sum += charToInt(s[i]);
    }
    cout << ((sum % 9 == 0) ? "Yes" : "No");
}
