

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    if(s=="Sunny" && s!="Rainy")
    {
        cout<<"Cloudy"<<endl;
    }
    else if(s=="Cloudy" && s!="Sunny")
    {
        cout<<"Rainy"<<endl;
    }
    else if(s=="Rainy" && s!="Cloudy")
    {
        cout<<"Sunny"<<endl;
    }
}










