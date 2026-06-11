#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using graph = vector<vector<char>>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
using pll = pair<ll, ll>;

int main() {
  ll a,b,c; cin>>a>>b>>c;
  if(c-a-b<=0){cout<<"No";}
  else if((c-a-b)*(c-a-b)>a*b*4){cout<<"Yes";}
  else{cout<<"No";}//cout<<a*b;  
}
   