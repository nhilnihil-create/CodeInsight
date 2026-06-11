#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b;
    if(a>0&&a<101&&b>0&&b<101)
    {
        b=b*2;
        c=a-b;
        if(c<0)
        {
            c=0;
        }
        cout<<c<<endl;
    }
    return 0;
}
