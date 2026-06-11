#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn =1e5+10;
const int mod=1e9+7;

int n;

void dfs(string s,int num)
{
    if(s.size()==n)
    {
        cout<<s<<'\n';
        return;
    }
    for(int i=0;i<=num;i++)
    {
        char d=('a'+i);
        string k=s;
        k+=d;
        if(i!=num)
            dfs(k,num);
        else
            dfs(k,num+1);
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    string s;
    dfs(s,0);




}
