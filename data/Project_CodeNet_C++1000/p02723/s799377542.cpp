#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int l=s.length();

        if(s[2]==s[3]&&s[4]==s[5])
         cout<<"Yes";
        else
         cout<<"No";
    return 0;
}
