#include <iostream>
 
using namespace std;
 
int main()
{
    
        string s;
    cin>>s;
    if(s[0]=='R'&&s[1]=='R'&&s[2]=='R') cout<<3;
 
    else if(s[0]=='R'&&s[2]=='R')cout<<1<<endl;
    else if(s[0]=='R'&&s[1]=='R')cout<<2<<endl;
    else if(s[1]=='R'&&s[2]=='R')cout<<2<<endl;
else if(s[0]!='R'&&s[1]!='R'&&s[2]=='R') cout<<1;
else if(s[0]=='R'&&s[1]!='R'&&s[2]!='R') cout<<1;
else if(s[0]!='R'&&s[1]=='R'&&s[2]!='R') cout<<1;
    else if(s[0]!='R'&&s[2]!='R') cout<<0;
    else if(s[0]!='R'&&s[1]!='R') cout<<0;
    else if(s[0]!='R'&&s[1]!='R'&&s[2]!='R') cout<<0;
 
 
 
 
    return 0;
}