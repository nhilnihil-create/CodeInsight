#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str = "";
    long long num, rem;
    bool flag = true;

    cin >> num;

    while(num > 0)
    {
        rem = num % 26;
        num /= 26;
        if(rem == 0)
        {
            rem = 26;
            num--;
        }
        str += (char)(rem + 96);
    }
    for(int i = str.length() - 1; i >= 0; i--)
        cout << str[i];
    cout << endl;
    return 0;
}