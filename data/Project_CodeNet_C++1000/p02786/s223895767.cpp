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
  ll H; cin >> H;
  ll num = 1;
  ll cnt = 1;
  while(H != 1){
    H /= 2;
    num *= 2;
    cnt += num;
  }
  cout << (cnt / 2) + num << endl;
}