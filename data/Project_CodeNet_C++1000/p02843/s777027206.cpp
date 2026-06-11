#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int ll
#define pb push_back
#define setbits(x)          __builtin_popcountll(x)
#define endl "\n"
typedef long long ll;
int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
queue<int> q;
int x;
cin>>x;
for(int i=100;i<=105;i++)
q.push(i);
map<int,int> mp;
while(q.front()<=x)
{
    int val=q.front();
    if(val==x)
    {
        cout<<1<<endl;
        return 0;
    }
    q.pop();
    for(int i=100;i<=105;i++)
    {
        if(mp[val+i]==0)
        {
            mp[val+i]=1;
            q.push(val+i);
        }
    }
}
cout<<0<<endl;




    return 0;
}

