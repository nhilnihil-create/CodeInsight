#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    if(s.length()&1){cout<<"No";return 0;}
    for(int i=0 ; i<s.length() ; i+=2)
    {
        string str;
        str+=s[i];
        str+=s[i+1];
        if(str!="hi") {cout << "No";return 0;}
    }
    cout << "Yes";
}
