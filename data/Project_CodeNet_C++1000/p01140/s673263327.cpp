#include<bits/stdc++.h>

#define INF 1e9
#define llINF 1e18
#define MOD 1e9+7
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
using namespace std;
int main(){
  int n,m;
  while(cin>>n>>m,n){
    int num[2500100]={};
    int takasa[10600]={};
    int num2[10600]={};
    ll ans=0;
    for(int i=1;i<=n;i++){
      int a;cin>>a;
      takasa[i]=takasa[i-1]+a;
    }
    for(int i=1;i<=m;i++){
      int a;cin>>a;
	num2[i]=num2[i-1]+a;
      for(int j=0;j<i;j++){
	num[num2[i]-num2[j]]++;
      }
    }
    for(int i=0;i<=n;i++){
      for(int j=0;j<i;j++){
	ans+=num[takasa[i]-takasa[j]];
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}

