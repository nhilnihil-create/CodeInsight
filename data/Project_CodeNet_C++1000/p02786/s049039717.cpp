#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;


int main(){
  ll h;
  cin >> h;

  ll sum=0,s=1;

  for(ll i=0;s<=h;i++){
    s=s*2;
    sum=s/2;
  }

  cout << sum+(sum-1) << endl;

  }
