#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()

void solve()
{
  int k,n;
  cin>>k>>n;
  vector<int>v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
    sort(all(v));
    int ans=v[0]+k-v[n-1];
    for(int i=0;i<n;i++){
        int dis=v[i+1]-v[i];
        ans=max(ans,dis);
    }
    cout<<k-ans<<endl;
}

int main()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

        solve();

    return 0;
}

