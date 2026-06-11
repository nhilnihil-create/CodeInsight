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
  int n; cin >> n;
  vector<int> a(n,0);

  rep(i,n-1){
    int t; cin >> t;
    a.at(t-1)++;
  }

  rep(i,n){
    cout << a.at(i) << endl;
  }
}
