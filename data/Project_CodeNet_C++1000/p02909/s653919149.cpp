#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    if(s == "Sunny")
        cout << "Cloudy\n";
    if(s == "Cloudy")
        cout << "Rainy\n";
    if(s == "Rainy")
        cout << "Sunny\n";

    return 0;
}
