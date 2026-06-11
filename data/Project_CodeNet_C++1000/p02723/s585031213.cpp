#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    int ans=0;
    cin>>s;
    if(s[2]==s[3])
        ans++;
    if(s[4]==s[5])
        ans++;
    if(ans==2)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}