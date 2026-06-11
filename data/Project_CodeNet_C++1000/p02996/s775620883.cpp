#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<pair<int,int>> pairs(N);
  vector<int> d(N);
  for(int i=0;i<N;i++){
    int a,b;
    cin >> a >> b;
    pairs[i].first=b;
    pairs[i].second=a;
  }
  sort(pairs.begin(),pairs.end());
  int cnt=0;
  bool can=true;
  for(int i=0;i<N;i++){
    cnt+=pairs[i].second;
    if(cnt>pairs[i].first){
      can=false;
      break;
    }
  }
  if(can){
    cout << "Yes" <<endl;
  }
  else{
    cout << "No" <<endl;
  }
}
    
  