#include <iostream>
#include <cstring>
using namespace std;


string s;



int main()
{
    cin >> s;
    for (int i = 0; i < s.size(); i+=2)
    if (s[i] == 'h' && s[i+1] == 'i')
    {

    }
    else
    {
        cout << "No";
        return 0;
    }
    cout << "Yes";
    return 0;
}
