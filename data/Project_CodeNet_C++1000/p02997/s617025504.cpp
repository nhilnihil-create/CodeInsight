#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
  
  int n,k; cin>>n>>k;
  if(k>n*(n-1)/2-(n-1)) {
    cout << -1 << endl;
    return 0;
  }
  vector<vector<int>> a(n);
  for(int i=0; i<n-1; i++){
    a.at(0).push_back(i+1);
    a.at(i+1).push_back(0);
  }
  k = n*(n-1)/2-(n-1)-k;
  cout << k+n-1<<endl;
  int now{1};
  for(int i=0; i<k; i++){
    if(a.at(now).back()==n-1) now++;
    if(a.at(now).back()+1==now){
      a.at(now).push_back(now+1);
      a.at(now+1).push_back(now);
    }
    else {
      int x = a.at(now).back();
      a.at(now).push_back(x+1);
      a.at(x+1).push_back(now);
    }
  }
  for(int i=0; i<n; i++){
    for(auto j:a.at(i)){
      if(i<j) cout <<i+1<<' '<<j+1<<endl;
    }
  }
}

