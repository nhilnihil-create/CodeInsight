#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
int main() {
  int n,in; cin>>n;
  vector<P> a(n); for(int i=0;i<n;i++) cin>>in,a[i]=P(in,i+1);
  sort(a.begin(),a.end());
  for(int i=0;i<n;i++) cout<<a[i].second<<" ";
}