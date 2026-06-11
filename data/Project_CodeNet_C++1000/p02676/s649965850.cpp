#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	string s,tem;
    int n;
    cin>>n;
    cin>>s;
    if(s.size()<=n)
    {
        cout<<s<<endl;
    }
    else
    {
        tem = s.substr(0,n);
        tem = tem+"...";
        cout<<tem<<endl;
    }
    return 0;
}
