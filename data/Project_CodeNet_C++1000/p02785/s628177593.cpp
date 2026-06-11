#include <bits/stdc++.h>
using namespace std;
#define REP(n) for(int i=0;i<(int)(n);i++)
int main() {
  int n,k;long long S=0;cin>>n>>k;vector<int>h(n);
  REP(n)cin>>h[i];sort(h.begin(),h.end());REP(n-k)S+=h[i];
  cout<<S<<endl;
}