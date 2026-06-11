#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rapido ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define pra(a) fl(i,0,a.size()) cout<<a[i]<<endl;

int32_t main()
{
  	rapido;
    int n; cin>>n;
    int x,y; cin>>x>>y;
    vector<int> cnt(n-1);
    for(int i = 1  ; i <=n; i++)
    {
        for(int j = i+1; j <= n; j++)
            cnt[min(j-i,min(abs(i-x) + abs(j-y), abs(j-x)+ abs(i-y))+1)-1]++;
    }
  	for(int i=0;i<cnt.size();i++)
      cout<<cnt[i]<<endl;
    return 0;
}