#include<iostream>
#include<map>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n<600)
        cout<<"8\n";
    else if(n<800)
        cout<<"7\n";
    else if(n<1000)
        cout<<"6\n";
    else if(n<1200)
        cout<<"5\n";
    else if(n<1400)
        cout<<"4\n";
    else if(n<1600)
        cout<<"3\n";
    else if(n<1800)
        cout<<"2\n";
    else if(n<2000)
        cout<<"1\n";
}