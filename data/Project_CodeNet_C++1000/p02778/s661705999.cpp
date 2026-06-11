#include<bits/stdc++.h>
using namespace std;
int main ()
{
    string str;
    cin>>str;

    int len = str.size();
    for(int i=0; i<len; i++)
    {

        str[i]='x';
    }
    cout<<str<<endl;
    return 0;
}
