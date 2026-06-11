#include <iostream>
#include <math.h>
#include <string>

using namespace std;
int main()
{
    string a;
    cin>>a;
    if(a == "Sunny"){
        cout<<"Cloudy";
    }
    else if(a == "Cloudy"){
        cout<<"Rainy";
    }
    else if(a == "Rainy"){
        cout<<"Sunny";
    }

    return 0;
}