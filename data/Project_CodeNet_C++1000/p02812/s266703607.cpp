#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    int n,ans=0;
    string s;
    cin>>n>>s;
    for(int i=0;i<n-2;i++) ans += s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C';
    cout<<ans;
}