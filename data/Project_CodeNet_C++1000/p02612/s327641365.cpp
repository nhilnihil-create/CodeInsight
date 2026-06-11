#include<iostream>
using namespace std;
int main()
{
    int n,c;
    int y=1000;
    cin>>n;

    while(n>y){
        y=y+1000;
    }
    c = y-n;

    cout<<c<<endl;
    return 0;
}

