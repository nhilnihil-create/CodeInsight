#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    // getline(cin, str);

    array<int, 26> arr{};

    // for (long unsigned int i = 0; i < str.length(); i++) {
    //     if ('a' <= str[i] && str[i] <= 'z') {
    //         arr[str[i] - 'a']++;
    //     } else if ('A' <= str[i] && str[i] <= 'Z') {
    //         arr[str[i] - 'A']++;
    //     }
    // }

    while (getline(cin, str))
    {
        for (long unsigned int i = 0; i < str.length(); i++)
        {
            if ('a' <= str[i] && str[i] <= 'z')
            {
                arr[str[i] - 'a']++;
            }
            else if ('A' <= str[i] && str[i] <= 'Z')
            {
                arr[str[i] - 'A']++;
            }
        }
    }

    for (int i = 0; i < 26; i++)
    {
        cout << static_cast<char>('a' + i) << " : " << arr[i] << endl;
    }
    return 0;
}
