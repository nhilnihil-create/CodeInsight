#include <bits/stdc++.h>
#define ll long long int
using namespace std;
bool isPalin(string s)
{
     string p=s;
    reverse(p.begin(),p.end());
    if(p==s)
    return true;
    else 
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    int n=s.size();
    string f=s.substr(0,(n-1)/2);
    string d=s.substr((n+3)/2-1,(n-1)/2);
    if(isPalin(s) &&  isPalin(f) && isPalin(d))
    cout<<"Yes\n";
    else
    cout<<"No\n";
}