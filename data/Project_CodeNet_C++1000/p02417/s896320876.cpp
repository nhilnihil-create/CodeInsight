#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    const int SIZE = 26;
    string line;
    int counter[SIZE];

    memset(counter, 0, sizeof(counter));
    while(getline(cin, line))
    {
        for(int i = 0; i < line.length(); i++)
        {
            if(isalpha(line[i]))
            {
                counter[(char)tolower(line[i])-'a']++;
            }
        }
    }

    for(int i = 0; i < SIZE; i++)
    {
        cout << (char)('a' + i) << " : " << counter[i] << endl;
    }

    return 0;
}