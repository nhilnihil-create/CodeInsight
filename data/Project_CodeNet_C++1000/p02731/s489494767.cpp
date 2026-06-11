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
    int l;
    cin>>l;
    cout<<setprecision(10)<<fixed<<(l*l*l)/(27.0)<<'\n';
}