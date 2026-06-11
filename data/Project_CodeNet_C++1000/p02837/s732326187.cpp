#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  int n; 
  cin>>n;
  vector<pair<int,int>>a[100];
  for(int i=0;i<n;i++){
      int l; 
      cin>>l;
     for (int j=0;j<l;j++){
        int x,y; 
        cin>>x>>y;
       a[i].push_back(make_pair(x-1,y));
    }
  }
  ll ans=0;
  for(int i=0; i<(1<<n); i++){
    int flag=1;
    ll cnt=0;
    for (int j=0;j<n;j++){
      
      if((i>>j)&1){
        cnt++;
        for(auto x : a[j]){
          if(x.second==1 && !((i>>x.first)&1)||x.second==0 &&  ((i>>x.first)&1)) 
            flag=0;
        }
    }
        
    }
    if(flag) 
       ans=max(ans,cnt);
  }
  cout<<ans<<endl;
}

