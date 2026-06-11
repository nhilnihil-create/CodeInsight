#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;

ll INF = 1e+18;
int iINF = 1e9;

vector<ll> memo(51, 0);

int 
main()
{
  int H, A; cin >> H >> A;
  if(H % A == 0)cout << H / A << endl;
  else cout << (H / A) + 1 << endl;

}