#include<bits/stdc++.h>
using namespace std;
void sunday(string s)
{
    if(s == "SUN")
        cout<<7;
    else if(s == "MON")
        cout<<6;
    else if(s == "TUE")
        cout<<5;
    else if(s == "WED")
        cout<<4;
    else if(s == "THU")
        cout<<3;
    else if(s == "FRI")
        cout<<2;
    else if(s == "SAT")
        cout<<1;
}
int main()
{
    string s;
    cin>>s;
    sunday(s);
    return 0;
}