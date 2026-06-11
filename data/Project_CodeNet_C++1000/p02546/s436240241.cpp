#include<iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int  length = s.size();
    if(s[length-1]=='s')
    {
        s+="es";
    }
    else
    {
        s+="s";
    }

    cout<<s<<endl;

    return 0;
}
