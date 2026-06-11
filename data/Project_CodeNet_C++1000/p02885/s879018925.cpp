#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a,b;
    cin>>a;
    cin>>b;

    int c = a-2*b;

    if(c>0){
        cout<<c;
    }
    else {
        cout<<0;
    }



    return 0;
}