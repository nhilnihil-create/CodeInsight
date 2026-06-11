#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    string s;
    cin>>s;
    if(s[0]=='S')
        cout<<"Cloudy";
    else if(s[0]=='C')
        cout<<"Rainy";
    else if(s[0]=='R')
    cout<<"Sunny";


    return 0;
}
