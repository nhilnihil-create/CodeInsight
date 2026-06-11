#include <iostream>
using namespace std;

int main() {
    string s;
    cin>>s;
    int a;
    if(s=="Sunny")
        a=0;
    else if(s=="Cloudy")
        a=1;
    else if(s=="Rainy")
        a=2;
    switch(a){
        case 0:cout<<"Cloudy"<<endl;
            break;

        case 1:cout<<"Rainy"<<endl;
            break;

        case 2:cout<<"Sunny"<<endl;
            break;
    }
    return 0;
}