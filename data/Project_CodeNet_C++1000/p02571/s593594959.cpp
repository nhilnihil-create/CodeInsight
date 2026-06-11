#include<bits/stdc++.h>
using namespace std;
string s,t;
int n,m,d,mn;
int main()
{
    cin >> s >> t;
    n=s.length();
    m=t.length();
    mn=m;
    for(int i=0; i<n-m+1; i++){
        d=0;
        for(int j=0; j<m; j++) d+=(s[i+j]!=t[j]);
        mn=min(mn,d);
    }
    cout << mn;
    return 0;
}