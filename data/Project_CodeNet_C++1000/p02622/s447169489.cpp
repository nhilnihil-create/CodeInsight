#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main()
{
    string s,t;
    long long c=0;
    cin>>s>>t;
    int len=s.length();
    for (int i=0;i<len;i++)
    {
        if (s[i]==t[i])continue;
        else c++;
    }
    cout<<c;
}
