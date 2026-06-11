#include<iostream>
using namespace std;
int main()
{
    int n,Count=0;
    cin>>n;
    for(int a=1; a<=9; ++a)
    {
        for(int b=1; b<=9; ++b)
        {
            if(a*b==n)
            {
                Count++;
            }
        }
    }
    if(Count==0)
    {
        cout<<"No"<<endl;
    }
    else
    {
        cout<<"Yes"<<endl;
    }
    return 0;
}
