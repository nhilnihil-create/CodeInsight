#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> a(1000001);
int n;

bool pairwise() {
  // cout << "0" << endl;
  vector<int> d(1000001);
  d[1]=1;
  vector<bool> sieve(1000001,true);
  int maxa = 0;
  for(int i=0;i<n;i++) {
    maxa = max(maxa, a[i]);
    // d[a[i]] = a[i];
    // sieve[a[i]] = false;
  }
  // cout << "1" << endl;
  for(int i=2;i<=maxa;i++) {
    if(sieve[i]) {
      for(int j=i;j<=maxa;j+=i) {
        if(j) {
          d[j]=i;
          sieve[j]=false;
        }
      }
    }
  }
  // cout << "2" << endl;
  // for(int i=0;i<=maxa;i++) cout << d[i] << sieve[i]<< endl;
  unordered_set<int> div;
  for(int i=0;i<n;i++){
    int e = a[i];
    while(e!=1) {
      // cout << d[e] << endl;
      if(div.find(d[e])!=div.end()) {
        // cout << "!" << d[e] << endl;
        return false;
      }
      div.insert(d[e]);
      int f = d[e];
      // e/=d[e];
      while(e%f==0) e/=f;
    }
  }
  // cout << "3" << endl;
  return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 

    // int n;
    cin >> n;
    // vector<int> a(n);
    for(int i=0;i<n;i++) {
      cin >> a[i];
    }

    bool p = pairwise();
    // bool p = true;
    if(p) {
      cout << "pairwise coprime";
      return 0;
    }

    int g = a[0];
    for(int i=1;i<n;i++) g = __gcd(g,a[i]);
    if(g==1) {
      cout << "setwise coprime";
      return 0;
    }

    cout << "not coprime";

    return 0;
}