#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,sum = 0,i;string s;cin >> n;bool sleep = false;
  pair<string,int> q[n];
  for(i=0;i<n;i++) cin >> q[i].first >> q[i].second;
  cin >> s;
  for(i=0;i<n;i++){
    if(sleep) sum += q[i].second;
    if(s==q[i].first) sleep = true;
  }
  cout << sum << "\n";
}