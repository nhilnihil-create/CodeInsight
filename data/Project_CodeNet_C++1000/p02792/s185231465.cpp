#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n;
  cin >> n;

  ll dp[200010]={};
  for(ll i=1;i<10;i++)dp[i]=i;

  for(ll i=10;i<=n;i++){
    dp[i]+=dp[i-1];
    if(i%10==0)continue;
    ll e=0;
    while(pow(10,e)<i)e++;
    e--;
    if(i/((ll) pow(10,e))==i%10){
      dp[i]++;//iの頭と最後が同じ場合
      ll  j=i;
      j-=i/((ll) pow(10,e))*pow(10,e);
      j/=10;
      //cout << i << " " << j << endl;
      ll ep=e,a=0;
      if(i>=100){
        ep--;
        a++;
      }
      dp[i]+=2*((pow(10,ep)-1)/9+j+a);
      //cout << i << endl;
    }
    else if(i/((ll) pow(10,e))>i%10){
      dp[i]+=2*((pow(10,e)-1)/9);
    }
    else{
      dp[i]+=2*((pow(10,e-1)-1)/9);
    }
  }

  cout << dp[n] << endl;

}