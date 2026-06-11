#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main()
{
    int h,n;
    cin>>h>>n;
    rep(i,n)
    {
        int a;
        cin>>a;
        h-=a;
        if(h<=0)
        {
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
}