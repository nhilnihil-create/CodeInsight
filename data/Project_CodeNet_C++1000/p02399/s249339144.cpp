#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int c=a/b;
    int d=a%b;
    double e=double(a)/double(b);
    cout<<c<<" "<<d<<" "<<fixed<<e<<endl;
    
    return 0;
}