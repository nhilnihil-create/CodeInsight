#include <iostream>
#include<bits/stdc++.h> 
using namespace std;

int main()
{
    string s;
    cin>>s;
    char c = s[s.length()-1];
    if(c == 's')
    s = s + "es";
    else 
    s = s +"s";
    cout<<s<<endl;
   
   
   return 0;
}