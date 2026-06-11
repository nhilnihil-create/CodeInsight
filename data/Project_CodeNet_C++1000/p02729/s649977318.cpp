#include<bits/stdc++.h>
using namespace std;
                       ///****   Hasebul Hassan Chowdhury ***////
#define ms(a,v)        memset(a,v,sizeof a)
#define lll            long long
#define FOR(i,a,b)     for(int i=a;i<=b;i++)
#define fast           ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Read           freopen("input.txt", "r", stdin)
#define Write          freopen("output.txt", "w", stdout)
#define INF            1000000000


int main()
{
    int n,m,cnt=0;
    cin>>n>>m;
    vector<int>v;
    int id=2;
    for(int i=1;i<=n;i++)
    {
        v.push_back(id);
        //cout<<id<<endl;
        id+=2;
    }
    //cout<<"id"<<endl;
    id=1;
    for(int i=1;i<=m;i++)
    {
        v.push_back(id);
        id+=2;
    }
    sort(v.begin(),v.end());
    //cout<<"Ok"<<endl;
    for(int i=0;i<v.size();i++)
    {
        for(int j=i+1;j<v.size();j++)
        {
            if((v[i]+v[j])%2==0) cnt++;
        }
    }
    cout<<cnt<<endl;
}
