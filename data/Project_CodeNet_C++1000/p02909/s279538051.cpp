#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    map<string,string> tenki;
    tenki["Sunny"]="Cloudy";
    tenki["Cloudy"]="Rainy";
    tenki["Rainy"]="Sunny";
    cout << tenki.at(s) << endl;
}