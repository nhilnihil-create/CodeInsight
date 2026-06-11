#include<bits/stdc++.h>
using namespace std;
#define w(x) cout << (#x) << " is " << x << "\n" ;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
    int n,mx=0;
    string s ;
    map<string,int>m;
    cin >> n ;
    while(n--)
    {
        cin >> s ;
        mx=max(++m[s],mx);
    }
    for(auto i:m)
    {
        if(i.second==mx)
            cout << i.first << "\n";
    }
    return 0;
}