#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;
using ll=long long;

int main() {
  ll N, m=0;
  cin >> N;
  vector<string> S(N);
  set<string> ss;
  map<string,ll> M;
  for (ll i=0; i<N; i++) {
    cin >> S[i];
    sort(S[i].begin(), S[i].end());
    ss.insert(S[i]);
    M[S[i]]++;
  }
  
  for (ll i=0; i<S.size(); i++) {
    string sss=S[i];
    if (ss.count(sss)) {
      ss.erase(sss);
      ll w=M[sss];
      m+=w*(w-1)/2;
    }
  }
  
  cout << m << endl;
}