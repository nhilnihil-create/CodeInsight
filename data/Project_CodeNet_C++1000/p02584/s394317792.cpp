#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
using namespace std;
ll n,t,x,y,m,q;

int main(){
      ios_base::sync_with_stdio(false); cin.tie(NULL);
      cin>>x>>n>>y;
      ll d=abs(x)/y;
      if(d>n) cout<<abs(abs(x)-n*y);
      else if((n-d)%2==0)cout<<abs(x)-d*y;
      else cout<<abs(abs(x)-(d+1)*y);
}