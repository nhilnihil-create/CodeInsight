#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<int(n);i++)
#define rep1(i,n) for(int i=1;i<int(n);i++)
#define all(a) (a).begin(),(a).end()
using ll = long long;
using ld = long double;
using Pint = pair<int,int>;
const ll mod = 1e9+7;

int main(){
  int n;
  cin>>n;
  vector<int> as(n);
  rep(i,n) cin>>as[i];

  int num=1;
  rep(i,n) if(num==as[i]) num++;

  if(num==1) cout<<-1<<endl;
  else cout<<n-num+1<<endl;

  return 0;
}