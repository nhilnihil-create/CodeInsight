#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<P> v(n);
  for(int i=0; i<n; ++i){
    cin >> v[i].first;
    v[i].second = i+1;
  }
  sort(v.begin(),v.end());
  for(int i=0; i<n; ++i){
    printf("%d",v[i].second);
    if(i == n-1) printf("\n");
    else printf(" ");
  }
}