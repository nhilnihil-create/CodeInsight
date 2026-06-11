#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;
int64_t large = 9223372036854775807;

int main()
{
    string S;
    cin >> S;
    if (S == "Sunny")
        cout << "Cloudy";
    if (S == "Cloudy")
        cout << "Rainy";
    if (S == "Rainy")
        cout << "Sunny";
}