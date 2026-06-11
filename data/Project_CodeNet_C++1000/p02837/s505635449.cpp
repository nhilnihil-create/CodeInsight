#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<pair<int,int>>>data(N);
  for(int i=0;i<N;i++){
    int L;
    cin >> L;
    for(int j=0;j<L;j++){
      int x,y;
      cin >> x >> y;
      x--;
      data.at(i).push_back(make_pair(x,y));
    }
  }
  
  int ans=0;
  for (int tmp = 0; tmp < (1 << N); tmp++) {
    bitset<15> s(tmp);
    bool a=true;
    for(int i=0;i<N;i++){
      if(((1<<i)&tmp)!=0){
        for(int j=0;j<data.at(i).size();j++){
          if(((1<<data.at(i).at(j).first)&tmp)==0&&data.at(i).at(j).second==1){
            //cout << tmp << " " << i  <<" " << j << endl;
            a=false;
          }
          else if(((1<<data.at(i).at(j).first)&tmp)!=0&&data.at(i).at(j).second==0) {
            //cout << tmp << " " << i  << j << endl;
            a=false;
          }
        }
      }
    }
    int l=s.count();
    if(a) {
      ans=max(ans,l);
      //cout << tmp << endl;
    }
  }
  
  cout << ans;
}