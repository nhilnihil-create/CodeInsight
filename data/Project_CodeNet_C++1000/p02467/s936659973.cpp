#include<bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
#define ll long long
using namespace std;

map<int, int> solve(int n) {
  map<int, int> res;
  for (int i=2; i*i<=n; i++) {
    while (n%i==0) {
      ++res[i];
      n/=i;
    }
  }
  if (n!=1) res[n]=1;
  return res;
}

int main() {
  int n; cin>>n;
  map<int, int> A=solve(n);
  cout<<n<<":";
  for (auto itr=A.begin(); itr!=A.end(); itr++) {
    cout<<" ";
    int loop=(itr->second);
    rep(i, loop) {
      if (i) cout<<" ";
      cout<<(itr->first);
    }
  }
  cout<<endl;
}

