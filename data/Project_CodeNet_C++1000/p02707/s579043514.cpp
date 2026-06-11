#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>adj[200005];
main()
{
    int n;
    cin>>n;
    map<int,int>cnt;
    for(int i=1;i<n;i++){
        int x;
        cin>>x;
        cnt[x]++;
    }
    for(int i=1;i<=n;i++) cout<<cnt[i]<<endl;

}
