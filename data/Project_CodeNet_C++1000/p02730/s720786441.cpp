#include<bits/stdc++.h>
using namespace std;
bool solve(string s)
{
    string t=s;
    reverse(t.begin(),t.end());
    if(s==t) return true;
    else return false;
}
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    string s1=s.substr(0,(n-1)/2),s2=s.substr((n+3)/2-1);
    if(solve(s)==true&&solve(s1)==true&&solve(s2)==true) cout<<"Yes";
    else cout<<"No";
}