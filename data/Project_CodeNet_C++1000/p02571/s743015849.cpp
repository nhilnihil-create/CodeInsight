#include <string>
#include <iostream>
#define min(a, b) a > b ? b : a

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    int min_change = 1000;
    for (int i = 0; i < s1.length() - s2.length() + 1; i++)
    {
        int cnt = 0;
        for (int j = 0; j < s2.length(); j++)
        {
            if (s1[j + i] != s2[j])
                cnt++;
        }
        min_change = min(min_change, cnt);
    }
    cout << min_change;

    return 0;
}