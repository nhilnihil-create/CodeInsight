#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main()
{
    int a,b;
    cin>>a>>b;
    for(int i=1;i<=10100;i++)
    {
        int x=(8*i)/100,y=(10*i)/100;
        if(a==x&&b==y) 
        {
            cout<<i;
            return 0;
        }
    }
    cout<<"-1";
}
    