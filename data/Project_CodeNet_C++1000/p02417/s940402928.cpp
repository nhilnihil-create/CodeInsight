#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int counter[26] = {};
    char ch;
    while (scanf("%c", &ch) != EOF)
    {
        if (ch >= 'a' && ch <= 'z')
            counter[ch - 'a']++;
        else if (ch >= 'A' && ch <= 'Z')
            counter[ch - 'A']++;
    }
    for (int i = 0; i < 26; i++)
        printf("%c : %d\n", 'a' + i, counter[i]);
}
