#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    if(int(s[0])>=65&&int(s[0])<=90)
    {
        cout<<'A';
    }
    else
    {
        cout<<'a';
    }
}