#include<iostream>
#include<cstring>
using namespace std;
int main ()
{
    char S[50];
    cin>>S;
    if (strcmp("ABC",S)==0)
    cout<<"ARC"<<endl;
    if (strcmp("ARC",S)==0)
    cout<<"ABC"<<endl;
    return 0;
}
