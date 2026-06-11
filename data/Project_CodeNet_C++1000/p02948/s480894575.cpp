#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int n,m;
  cin >> n >> m;
  vector<pair<int,int>> ab(n);
  for(int i=0;i<n;++i){
    int a,b;
    cin >> a >> b;
    ab[i] = make_pair(a,b);
  }

  sort(ab.begin(),ab.end());
  priority_queue<int> kouho;
  ll ans=0;
  int j=0;
  for(int i=1;i<=m;++i){
    while(ab[j].first<=i && j<n){
      kouho.push(ab[j].second);
      j++;
    }
    if(kouho.size()){
      ans+=kouho.top();
      kouho.pop();
    }
  }
  cout << ans << endl;
  return 0;
}
