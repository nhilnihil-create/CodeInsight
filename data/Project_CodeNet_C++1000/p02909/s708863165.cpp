#include <iostream>

using namespace std;

int main()
{
    string x,Sunny,Cloudy,Rainy;
    cin>>x;
    if(x=="Sunny")
    {
        cout<<"Cloudy";
    }
    else if(x=="Cloudy")
    {
        cout<<"Rainy";
    }
    else if(x=="Rainy")
    {
        cout<<"Sunny";
    }

    return 0;
}