#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  ll a,b,c,k,count=0;
  cin>>a>>b>>c>>k;
  if(b<=a) count = (ll)(log2(a/(b*1.0)))+1;
  
  b = b*((ll)(pow(2,count)));
  //cout<<count<<" "<<b<<"\n";
  if(c<=b) count += (ll)(log2(b/(c*1.0)))+1;
  if(count<=k) cout<<"Yes\n";
  else cout<<"No\n";
  //cout<<count;
                        
                       
                        }