#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string x;

    for(int i=0; i<s.size(); i++)
        s.replace(i,1, "x");

    cout << s << endl;

    return 0;
}