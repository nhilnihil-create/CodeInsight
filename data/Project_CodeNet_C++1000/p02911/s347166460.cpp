#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define rep(i,n) for(int i=0; i<n; i++)
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end()) //sortしてから使う
#define INF 2147483647
#define LLINF 9223372036854775807LL

int main() {
  int n,k,q; cin>>n>>k>>q;
  vector<int>A(q);
  rep(i,q) cin>>A[i];
  vector<int>Point(n);
  rep(i,q) Point[A[i]-1]++;
  rep(i,n){
    if (Point[i] >= q-k+1) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}

