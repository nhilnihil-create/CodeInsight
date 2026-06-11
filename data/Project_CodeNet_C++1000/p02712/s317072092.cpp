#include <iostream>

using namespace std;

int main()
{
    long long a,b=0;
    cin>>a;
    for(int i=0;i<=a;i++)
    {
        if(i%3==0||i%5==0)
            b=b+0;
        else
            b=b+i;
    }
        cout<<b<<endl;
        return 0;
}