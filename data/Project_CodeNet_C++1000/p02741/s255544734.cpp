#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
const ll INF = 1LL<<60;
const ll M = pow(10,9)+7;
/*template*/


int main()
{
  ll a[32]={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
  ll k;cin>>k;
  cout<<a[k-1]<<endl;
  return 0;
}
