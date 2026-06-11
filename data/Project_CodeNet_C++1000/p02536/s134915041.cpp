#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

ll cnt[100003]={0};
vector< vector<ll> > arr(100003);

void func(ll i){
  if(arr[i].size()==0) return;
  ll j;
  cnt[i]=1;
  for(j=0;j<arr[i].size();j++){
    if(cnt[arr[i][j]]==0) func(arr[i][j]);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  ll n,m,i,j,count=0;
  cin>>n>>m;
  ll a,b;
  
  for(i=0;i<m;i++){
    cin>>a>>b;
    arr[a].pb(b); arr[b].pb(a);
  }
  
  for(i=1;i<=n;i++){
    if(cnt[i]) continue; 
    count++;
    func(i);
  }
  //for(i=1;i<=n;i++) cout<<cnt[i]<<" ";
  cout<<count-1<<"\n"; 
}
    