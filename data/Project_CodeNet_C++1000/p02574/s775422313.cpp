#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> a(1000001);
int n;

bool pairwise() {
  vector<int> d(1000001);
  d[1]=1;
  int maxa = 0;
  for(int i=0;i<n;i++) {
    maxa = max(maxa, a[i]);
  }
  vector<int> pr(1000001);
  int point=0;
  for (int i=2; i<=maxa; ++i) {
    if (d[i] == 0) {
        d[i] = i;
        pr[point++]=i;
    }
    for (int j=0; j<point && pr[j]<=d[i] && i*pr[j]<=maxa; ++j)
      d[i * pr[j]] = pr[j];
  }
  unordered_set<int> div;
  for(int i=0;i<n;i++){
    int e = a[i];
    while(e!=1) {
      if(div.find(d[e])!=div.end()) {
        return false;
      }
      div.insert(d[e]);
      int f = d[e];
      while(e%f==0) e/=f;
    }
  }
  return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 

    cin >> n;
    for(int i=0;i<n;i++) {
      cin >> a[i];
    }

    bool p = pairwise();
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