#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for (ll i=0; i<n; ++i)
#define all(c) begin(c),end(c)
#define PI acos(-1)
#define oo LLONG_MAX
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
/*

*/
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  string S;
  cin >> S;
  if (S == "RRR")
    cout << 3 << endl;
  else if (S == "RRS" || S== "SRR")
    cout << 2 << endl;
  else if (S== "SSS")
    cout << 0 << endl;
  else
    cout << 1 << endl;
           
}
