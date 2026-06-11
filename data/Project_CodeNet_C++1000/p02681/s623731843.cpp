#include <iostream>

using namespace std;

int main()
{
    string s,t;
    int sum=0;
    cin>>s>>t;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]==t[i])
        {
            sum++;
        }
    }
    if(sum==s.size())
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
}