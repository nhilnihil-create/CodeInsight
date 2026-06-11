#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
const int maxn=2e5+10;
const int mod=1e9+7;
int a[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cnt=1;
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=1;i<n;i++)
    {
        if(s[i]!=s[i-1])
            cnt++;
    }
    cout<<cnt<<'\n';

}
