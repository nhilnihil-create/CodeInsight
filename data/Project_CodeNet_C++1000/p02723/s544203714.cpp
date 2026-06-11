#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    char s[11];
    cin >> s;
    if(s[2]==s[3]&&s[4]==s[5]){
        cout <<     "Yes\n";
    }
    else
        cout <<"No";
    return 0;
}
