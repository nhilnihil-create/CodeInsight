#include<iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    for(unsigned int i=1;i<=s.size();i++)
    {
        if(i%2==1&&s[i-1]=='L')
        {
            cout<<"No";
            return 0;
        }
        if(i%2==0&&s[i-1]=='R')
        {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}