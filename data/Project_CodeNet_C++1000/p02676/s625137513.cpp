#include <iostream>
#include <string>
using namespace std;

int main()
{
    int k = 0;
    string str;
    cin >> k;
    cin >> str;
    if (str.size() > k)
    {
        for (int i = 0; i < k; i++)
            cout << str[i];
        cout << "...";
    }
    else
        cout << str;
    return 0;
}