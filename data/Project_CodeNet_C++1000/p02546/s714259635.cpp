#include <iostream>
#include <cstring>
using namespace std;
char str[10000];
int main()
{
    cin>>str;
    int n=strlen(str);
    if(str[n-1]=='s'){
        cout<<str<<"es"<<endl;
    }else{
        cout<<str<<'s'<<endl;
    }
}