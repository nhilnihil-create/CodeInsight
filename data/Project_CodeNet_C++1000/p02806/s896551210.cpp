#include <bits/stdc++.h>
using namespace std;

int main() {
  //ifstream in("input.txt");
  //cin.rdbuf(in.rdbuf());

  int N;
  cin>>N;
  vector< pair<string,int> > H(N);
  for(int i=0;i<N;i++) cin>>H.at(i).first>>H.at(i).second;

  string sleep;
  cin>>sleep;

  int ans=0;
  bool check=false;
  for(int i=0;i<N;i++){
    if(check){
      ans += H.at(i).second;
    }
    if(sleep==H.at(i).first) check=true;
  }
  
  cout<<ans<<endl;
}
