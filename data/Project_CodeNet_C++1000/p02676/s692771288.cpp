#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(s.length()<=n)
    {
        cout<<s;
    }
    else
    {
        cout<<s.substr(0,n)<<"...";
    }
}
