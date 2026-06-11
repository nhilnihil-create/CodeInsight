#include <bits/stdc++.h>

using namespace std;



int main()
{
    string a;
    cin>>a;
    if(a[0]!='R'&&a[1]!='R'&&a[2]!='R')cout<<0<<endl;
    else if(a[0]=='R'&&a[1]!='R')cout<<1<<endl;
    else if(a[0]=='R'&&a[1]=='R'&&a[2]=='R')cout<<3<<endl;
    else if(a[0]=='R'&&a[1]=='R'&&a[2]!='R')cout<<2<<endl;
    else if(a[0]!='R'&&a[1]=='R'&&a[2]=='R')cout<<2<<endl;
    else if(a[0]!='R'&&a[1]=='R'&&a[2]!='R')cout<<1<<endl;
    else if(a[0]!='R'&&a[1]!='R'&&a[2]=='R')cout<<1<<endl;
}
