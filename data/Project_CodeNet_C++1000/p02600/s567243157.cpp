#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    if(n>=1800)
        cout<<"1"<<endl;
    else if(n>=1600)
        cout<<"2"<<endl;
    else if(n>=1400)
        cout<<"3"<<endl;
    else if(n>=1200)
        cout<<"4"<<endl;
    else if(n>=1000)
        cout<<"5"<<endl;
    else if(n>=800)
        cout<<"6"<<endl;
    else if(n>=600)
        cout<<"7"<<endl;
    else
        cout<<"8"<<endl;
    return 0;
}
