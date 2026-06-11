#include<iostream>
using namespace std;
int main ()
{
    long long int a,b;
    int c=0;
    cin>>a>>b;
    for(int i=a; i>0; i=i-b)
    {
        c++;
    }
    cout<<c<<endl;
    return 0;
}
