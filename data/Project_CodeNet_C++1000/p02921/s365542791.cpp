#include<iostream>
#include<string>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;
    int sum=0;
    rep(i,s.size())
    {
        if(s[i]==t[i])sum++;
    }
    cout<<sum<<endl;

    return 0;
}