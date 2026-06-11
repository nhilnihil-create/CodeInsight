#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

map<string, string> mp;

int main()
{
    mp["Sunny"] = "Cloudy";
    mp["Cloudy"] = "Rainy";
    mp["Rainy"] = "Sunny";
    string s;
    cin >> s;
    cout << mp[s] << "\n";
}