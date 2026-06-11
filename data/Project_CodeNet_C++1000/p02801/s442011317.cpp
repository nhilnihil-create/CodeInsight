#include<iostream>

using namespace std;

int main()

{
    char s ;
    cin>>s ;

    if(s>='a' && s<='y')
    {
        cout<<(char)(s+1)<<endl ;
    }
    if(s>='A' && s<='Y')
    {
        cout<<(char)(s+1)<<endl ;
    }

    return 0;

}