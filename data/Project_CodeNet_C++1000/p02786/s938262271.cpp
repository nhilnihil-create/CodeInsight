#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define INF INT_MAX;
typedef long long ll;
using namespace std;

int main(){
  ll h; cin >> h;
  ll n = 1;
  while(n<=h) n*=2;
  cout <<  n-1 << endl;
}
