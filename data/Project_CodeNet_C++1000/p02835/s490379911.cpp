#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int A,B,C;
  cin>>A>>B>>C;
  if(A+B+C>21)cout<<"bust"<<endl;
  else cout<<"win"<<endl;
  return 0;
}