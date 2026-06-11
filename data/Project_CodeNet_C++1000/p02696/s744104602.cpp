#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back


int main() {
  ll a,b,n; cin>>a>>b>>n;
  cout<<a*min(b-1,n)/b<<endl;
}
