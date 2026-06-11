#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,c=0;
    string s;
    cin>>n>>s;
    for(i=0;i<s.size();i++)
    {
        if(s.substr(i,3)=="ABC")
            c++;
    }
    cout<<c<<endl;
}
