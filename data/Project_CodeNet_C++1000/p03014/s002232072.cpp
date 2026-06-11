#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,m;
  cin>>n>>m;
  vector<vector<ll>> mat(n,vector<ll>(m));
  for(ll i=0;i<n;i++)
    for(ll j=0;j<m;j++){
      char ch;
      cin>>ch;
      if(ch =='.')
        mat[i][j] = 1;
      else 
        mat[i][j]=0;
    }
    
  vector<vector<ll>> r(n,vector<ll>(m));
  vector<vector<ll>> l(n,vector<ll>(m));
  vector<vector<ll>> u(n,vector<ll>(m));
  vector<vector<ll>> d(n,vector<ll>(m));
  for(ll i=0;i<n;i++)
    for(ll j=0;j<m;j++){
      if(j==0)
        l[i][j] = mat[i][j];
      else if(mat[i][j])
        l[i][j] = l[i][j-1] +1;
    }
  
  for(ll i=0;i<n;i++)
    for(ll j=m-1;j>=0;j--){
      if(j==m-1)
        r[i][j] = mat[i][j];
      else if(mat[i][j])
        r[i][j] = r[i][j+1] +1;
    }
  
  for(ll i=0;i<n;i++)
    for(ll j=0;j<m;j++){
      if(i==0)
        u[i][j] = mat[i][j];
      else if(mat[i][j])
        u[i][j] = u[i-1][j] +1;
    }
  
  for(ll i=n-1;i>=0;i--)
    for(ll j=0;j<m;j++){
      if(i==n-1)
        d[i][j] = mat[i][j];
      else if(mat[i][j])
        d[i][j] = d[i+1][j] +1;
    }
  ll ans=0;
  
  for(ll i=0;i<n;i++)
    for(ll j=0;j<m;j++)
      ans = max(ans,l[i][j] + d[i][j] +u[i][j] + r[i][j] - 3);
    cout<<ans<<endl;
}