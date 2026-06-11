#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  int n,k;
  cin>>n>>k;
  
  vector<int>sunuke(n);
  rep(i,n)sunuke[i]=0;
  rep(i,k){
    int d;
    cin>>d;
    int temp=0;
    rep(j,d){
      cin>>temp;
      sunuke[temp-1]++;
    }
  }
  int ans=0;
  rep(i,n)if(sunuke[i]==0)ans++;  
  cout<<ans<<endl;
  return 0;
}