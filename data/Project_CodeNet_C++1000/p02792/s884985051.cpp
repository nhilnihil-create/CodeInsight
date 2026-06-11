#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N; 
  cin>>N;
  vector<vector<int>> S(10,vector<int>(10,0));
  vector<vector<bool>> C(10,vector<bool>(10,true));
  for(int i=1;i<=N;i++){
    string s = to_string(i);
    int si=s.size();
    int a=(s.at(0)-'0');
    int b=(s.at(si-1)-'0');
    S.at(a).at(b)++;
  }
  int ans=0;
  rep(i,10){
    rep(j,10){
      if(C.at(i).at(j)){
        if(i==0||j==0) continue;
        int a=S.at(i).at(j),b=S.at(j).at(i),d;
        if(i!=j) d=2*a*b;
        else d=a*b;
        ans+=d;
        C.at(j).at(i)=false;
      }
    }
  }
  cout<<ans;
}