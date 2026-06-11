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
  int H, N; cin >> H >> N;
  rep(i, 0, N){
    int tmp; cin >> tmp;
    H -= tmp;
  }

  if(H <= 0) cout << "Yes" << endl;
  else cout << "No" << endl;

}