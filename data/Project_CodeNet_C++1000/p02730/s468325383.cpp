#include<bits/stdc++.h>

using namespace std;

#define TC ll t; cin >> t; while(t--)
typedef long long ll;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s;
    bool isok=1;
    cin >> s;
    ll n=s.length(),l1,h1,l2,h2;
    l1=0; h1=(n-3)/2;
    l2=(n+1)/2; h2=n-1;
    while(l2<n && isok)
    {
        if(s[l1]!=s[h1] || s[l2]!=s[h2]) isok=0;
        l1++; h1--; l2++; h2--;
    }
    l1=0;
    while(l1<n && isok)
    {
        if(s[l1]!=s[n-l1-1]) isok=0;
        l1++;
    }
    if(!isok) cout << "No\n";
    else cout << "Yes\n";
    return 0;
}
