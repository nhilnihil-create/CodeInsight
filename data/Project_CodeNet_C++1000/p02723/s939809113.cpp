#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
    char str[80];
    cin>>str;
    if((str[2]==str[3]) && (str[4]==str[5]))
       cout<<"Yes";
    else
        cout<<"No";

    return 0;
}
