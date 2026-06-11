#include<iostream>

using namespace std ;

int main()

{
    long long int a ;
    char  s[15];

    cin>>a>>s;



    if(a>=3200)
    {
        cout<<s<<endl ;
    }
    else if(a<3200)
    {
        cout<<"red"<<endl ;
    }

    return 0;
}