#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,n) for(int i=0;i<n;i++)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int cnt=0;
    int n=s.length();
    for(int i=0;i<n/2;i++)
    {
        if(s[i]!=s[n-i-1])
            cnt++;
    }
    cout<<cnt;
}
