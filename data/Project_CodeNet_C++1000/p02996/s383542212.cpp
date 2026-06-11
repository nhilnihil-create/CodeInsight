#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<pair<int,int>>a(n);
  for(int i=0;i<n;i++){
    cin>>a[i].second>>a[i].first;
  }
  sort(a.begin(),a.end());
  long long wa=0;
  bool check=false;
  for(int i=0;i<n;i++){
    wa+=a[i].second;
    if(wa<=a[i].first){
      check=true;
    }else{
      check=false;
      break;
    }
  }
  if(check)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}
