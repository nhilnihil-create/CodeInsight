#include <iostream>
#include <bits/stdc++.h>

using namespace std;



int main()
{
    int cnt = 0;
    string str1, str2;
    cin >> str1 >> str2;

    for(int i = 0; i < str1.length(); i++)
    {
        if(str1[i] != str2[i])
            cnt++;
    }
    cout << cnt << endl;

    return 0;
}