#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    if((*str.rbegin())=='s')
    {
        str.append("es");

    }
    else
    {
        str.append("s");
    }
    cout<<str;
}