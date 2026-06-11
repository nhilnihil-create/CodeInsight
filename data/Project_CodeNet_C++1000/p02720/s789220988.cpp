#include<iostream>
#include<queue>
using namespace std;
using ll = long long;

int main() {
  queue<ll> q;
  for(int i=1;i<10;++i)q.push(i);
  int k;
  cin>>k;
  ll x;
  for(int i=0;i<k;++i) {
    x=q.front();
    q.pop();
    ll _x=x*10+x%10;
    if(x%10)q.push(_x-1);
    q.push(_x);
    if(x%10!=9)q.push(_x+1);
  }
  cout<<x<<endl;
}