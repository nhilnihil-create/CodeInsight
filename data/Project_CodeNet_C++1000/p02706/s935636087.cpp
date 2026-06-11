#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a;
        cin>>a;
        n-=a;
        if(n<0)
        {
            cout<<"-1";
            return 0;
        }
    }
    cout<<n;
}