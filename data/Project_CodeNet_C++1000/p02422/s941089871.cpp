#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
    string str;
    int n;
    cin >> str;
    cin >> n;

    string cmd;
    int a, b;
    string p;
    stringstream prints;
    while (n--)
    {
        cin >> cmd >> a >> b;

        if(cmd == "print")
            prints << str.substr(a, b-a+1) << endl;
        if(cmd == "reverse")
            reverse(&str[a], &str[b]+1);
        if(cmd == "replace"){
            cin >> p;
            str.replace(a, b-a+1, p);
        }

    }

    cout << prints.str();
}
