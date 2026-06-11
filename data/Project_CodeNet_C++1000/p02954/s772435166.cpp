#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  string s;
  cin >> s;
  ll n=s.size();
  ll ans[n];
  memset(ans,-1,sizeof(ans));

  for(int i=0;i<n;i++){
    if(ans[i]!=-1)continue;
    ll k=1;
    if(s[i]=='R'){
      while(s[i+k]==s[i]){
        k++;
      }
      if(k%2==0)ans[i]=i+k;
      else ans[i]=i+k-1;
      for(int j=i+1;j<i+k;j++){
        if(i%2==j%2)ans[j]=ans[i];
        else ans[j]=(i+k)+(i+k-1)-ans[i];
      }
    }
  }

  
  for(int i=n-1;i>0;i--){
    if(ans[i]!=-1)continue;
    ll k=1;
    if(s[i]=='L'){
      while(s[i-k]==s[i]){
        k++;
      }
      if(k%2==0)ans[i]=i-k;
      else ans[i]=i-k+1;
      for(int j=i;j>i-k;j--){
        if(i%2==j%2)ans[j]=ans[i];
        else ans[j]=(i-k)+(i-k+1)-ans[i];
      }
    }
  }

  ll b[n]={};
  for(int i=0;i<n;i++)b[ans[i]]++;
  for(int i=0;i<n;i++)cout << b[i] << " ";

  

}