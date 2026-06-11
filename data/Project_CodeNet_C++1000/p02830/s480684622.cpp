#include<iostream>
using namespace std;
int main()
{
    int n,i,j;
    cin>>n;
    string s,t,r;
    cin>>s>>t;
    for(i=0;i<n;i++)
    {
        r=r+s[i];
        r=r+t[i];
    }
    cout<<r;
}