#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
int main(){
  string S;
  cin>>S;
  string T="hi";
  for(int i=0;i<S.size()+1;i++){
    if(S==T){cout<<"Yes"<<endl;return 0;}
    T+="hi"; }
    cout<<"No"<<endl;
  return 0;
}