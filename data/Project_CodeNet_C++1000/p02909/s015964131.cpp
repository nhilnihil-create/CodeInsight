#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    if (str.compare("Sunny")==0)
        cout<<"Cloudy"<<endl;
    else if (str.compare("Cloudy")==0)
        cout<<"Rainy"<<endl;
    else if (str.compare("Rainy")==0)
        cout<<"Sunny"<<endl;
}