#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
const int maxn=2e5+10;
const int mod=998244353;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(auto &v:s)
    {
        int x=v-'A';
        x+=n;
        x%=26;
        v=char('A'+x);
    }
    cout<<s<<'\n';



}
