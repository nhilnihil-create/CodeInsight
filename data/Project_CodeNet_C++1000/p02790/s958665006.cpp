#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
    int a,b,r,s,i;
    cin >> a >> b;
    if(a>b)
    {
        r=a;
        s=b;
    }
    else
    {
        r=b;
        s=a;
    }
    stringstream ss;
ss << s;
string str = ss.str();
string k;
    for(i=0;i<r;i++)
    {
        k+=str;
    }
    cout << k ;
}
