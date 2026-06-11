#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	string s,t,tem;
    cin>>s>>t;
    tem=t.substr(0,s.size());
    cout<<(tem==s?"Yes":"No")<<endl;
    return 0;
}
