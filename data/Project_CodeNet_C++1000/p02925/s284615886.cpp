#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n;
  cin >> n;
  vector<queue<ll>> q(n);
  for(int i=0;i<n;i++){
    for(int j=0;j<n-1;j++){
      ll a;
      cin >> a;
      q[i].push(a-1);
    }
  }

  ll k=0,c=0,b=0;
  bool muri=false;
  vector<bool> sumi(n,0);

  while(c<n*(n-1)/2){
    sumi=vector<bool>(n,0);
    k=0;
    for(int i=0;i<n;i++){
      if(q[i].empty())continue;
      if(q[q[i].front()].empty()){
        muri=true;
        break;
      }
      if(i==q[q[i].front()].front() && sumi[i]==false && sumi[q[i].front()]==false){
        sumi[i]=true;
        sumi[q[i].front()]=true;
        q[q[i].front()].pop();
        q[i].pop();
        k++;
        c++;
      }
    }
    //cout << k << endl;
    if(k==0)muri=true;
    if(muri)break;
    b++;
  }

  if(muri)cout << -1 << endl;
  else cout << b <<endl;

}