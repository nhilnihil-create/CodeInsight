#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    float a= (float)n/1.08;
    int p =(int)a*1.08;
    int q =((int)a+1)*1.08;
    if(p==n)
    {
        cout<<a;
    }
    else if(q==n)
    {
        cout<<(int)a+1;
    }
    else
    {
        cout<<":(";
    }

}