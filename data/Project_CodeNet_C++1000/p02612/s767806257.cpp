#include<iostream>
using namespace std;
int main()
{
        long long int n,c,d;
        cin >>n;
        if((n%1000)==0)
        {
                cout<<"0"<<endl;
        }
        else
        {

                c=(n%1000);
                d=(1000-c);
                cout<<d<<endl;
        }
        return 0;
}
