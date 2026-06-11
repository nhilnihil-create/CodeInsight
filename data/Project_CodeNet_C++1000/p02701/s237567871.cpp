#include<bits/stdc++.h>
#define ll long long
#define vl vector
#define pb push_back
using namespace std;
int main()
{
    set<string> se;
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        string s;
        cin>>s;
        se.insert(s);
    }
    cout<<se.size();
    return 0;
}