#include <iostream>

using namespace std;

int main()
{
    int x;
    cin>>x;
    if(400<=x&&x<600){
        cout<<"8";
    }
    if(600<=x&&x<800){
        cout<<"7";
    }
    if(800<=x&&x<1000){
        cout<<"6";
    }
    if(1000<=x&&x<1200){
        cout<<"5";
    }

    if(1200<=x&&x<1400){
        cout<<"4";
    }

    if(1400<=x&&x<1600){
        cout<<"3";
    }
    if(1600<=x&&x<1800){
        cout<<"2";
    }
    if(1800<=x&&x<2000){
        cout<<"1";
    }
}
