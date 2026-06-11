#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    char s[4];
    cin >> s;
    if (s[1] == 'B')
    {
        cout << "ARC" << endl;
    }
    else
    {
        cout << "ABC" << endl;
    }
    return 0;
}
