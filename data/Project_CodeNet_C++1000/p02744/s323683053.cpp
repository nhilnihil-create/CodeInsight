#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
const int maxn=2e5+10;
const int mod=998244353;

int n;
int f[15];

void dfs(int cnt,string s)
{
    if(cnt>n)
    {
        cout<<s<<'\n';
        return;
    }
    for(int i=1;i<=cnt;i++)
    {
        string ss=s;
        if(f[i]==0)
            continue;
        ss+=char('a'+i-1);
        f[i+1]++;
        dfs(cnt+1,ss);
        f[i+1]--;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    string a;
    f[1]=1;
    dfs(1,a);











}
