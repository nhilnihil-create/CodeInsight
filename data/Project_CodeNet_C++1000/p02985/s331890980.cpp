#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
  int n,k;
  cin>>n>>k;
  vector<int> a[n];
  rep(i,n-1){
    int f,t;
    cin>>f>>t;
    a[f-1].push_back(t-1);
    a[t-1].push_back(f-1);
  }
  ll ans=k;
  queue<int> q;
  bool used[n];
  rep(i,n) used[i]=false;
  used[0]=true;
  rep(i,a[0].size()){
    ans=ans*(k-1-i)%mod;
    used[a[0][i]]=true;
    q.push(a[0][i]);
  }
  
  while(q.size()){
    int p=q.front();
    q.pop();
    int cur=k-2;
    rep(i,a[p].size()){
      if(used[a[p][i]]==false){
        ans=ans*cur%mod;
        used[a[p][i]]=true;
        q.push(a[p][i]);
        cur--;
      }
    }
  }
  cout<<ans<<endl;
}
