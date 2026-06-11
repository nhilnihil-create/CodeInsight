#include<iostream>
#include<cstring>

using namespace std  ;


int main()

{
    string str ;

    getline(cin, str) ;

    if(str=="Sunny")
    {
        cout<<"Cloudy"<<endl ;
    }

    else if(str=="Cloudy")
    {
        cout<<"Rainy"<<endl ;
    }

    if(str=="Rainy")
    {
        cout<<"Sunny"<<endl ;
    }

    return 0;
}