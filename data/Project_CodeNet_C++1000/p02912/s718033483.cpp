#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n,m;
  cin >> n >> m;
  priority_queue<ll,vector<ll>,less<ll>> q;
  for(int i=0;i<n;i++){
    ll a;
    cin >> a;
    q.push(a);
  }

  for(int i=0;i<m;i++){
    ll b=q.top();
    q.pop();
    b/=2;
    q.push(b);
  }

  ll s=0;
  for(int i=0;i<n;i++){
    ll c=q.top();
    q.pop();
    s+=c;
  }

  cout << s << endl;

  

}