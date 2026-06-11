#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n>399 && n<600)
        cout<<"8";
    else if(n>599 && n<800)
        cout<<"7";
    else if(n>799 && n<1000)
        cout<<"6";
    else if(n>999 && n<1200)
        cout<<"5";
    else if(n>1199 && n<1400)
        cout<<"4";
    else if(n>1399 && n<1600)
        cout<<"3";
    else if(n>1599 && n<1800)
        cout<<"2";
    else
        cout<<"1";
}
