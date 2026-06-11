#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    long long n,i;
    string s,t,r;
    cin>>n;
    cin>>s>>t;
    for(i=0;i<t.size();i++)
    {
        r.push_back(s[i]);
        r.push_back(t[i]);
    }
    cout<<r<<endl;
    return 0;
}