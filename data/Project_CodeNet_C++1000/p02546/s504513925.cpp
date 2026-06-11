#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int len=s.size()-1;
    if(s[len]!='s')s+='s';
    else if(s[len]=='s')s+='e',s+='s';
    cout<<s<<endl;
}
