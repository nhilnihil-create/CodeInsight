#include <iostream>
#include <string>
using namespace std;

int main()
{
    int cur_max = 0;
    int max_max = 0;
    string s;
    cin >> s;
    for (int i = 0; i < 3; i++)
    {
        if (s[i] == 'R')
        {
            cur_max += 1;
        }
        else
        {
            cur_max = 0;
        }
        if (cur_max > max_max)
        {
            max_max = cur_max;
        }
    }
    cout << max_max;
    return 0;
}