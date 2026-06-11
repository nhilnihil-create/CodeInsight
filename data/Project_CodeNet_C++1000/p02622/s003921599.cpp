#include <iostream>
using namespace std;

int main(void)

{
    char s[200000] = {0};
    char t[200000] = {0};
    int a, sum;
    sum = 0;
    cin >> s;
    cin >> t;
    for (a = 0; a < 200000; a++)
    {
        if (s[a] != t[a])
            sum++;
    }
    cout << sum << endl;
    return 0;
}