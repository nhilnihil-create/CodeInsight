#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s = "Sunny";
    string c = "Cloudy";
    string r = "Rainy";
    string x;
    cin >> x;
    if(x==s)
        cout << c;
    else if(x==c)
        cout << r;
    else
        cout << s;
}
