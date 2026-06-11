#include <bits/stdc++.h>
#define fio     ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define pi      3.14159265
#define ll      long long
#define repe    ll tc,cas=0;cin>>tc;while(tc--)
#define op      freopen("output.txt", "w", stdout);

#define maxn 10000010
using namespace std;

map<string,int>mp;
string s;

int main()
{
    fio;

    int n;
    cin>>n;



    for(int i=0;i<n;i++){
        cin>>s;
        mp[s]++;
    }
    int mx=-1;
    for(auto i: mp)
    {
        mx = max(mx,i.second);
    }

    for(auto i:mp)
    {
        if(i.second==mx)
            cout<<i.first<<endl;
    }

    return 0;
}
