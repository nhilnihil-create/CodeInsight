#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int A,B;
  cin>>A>>B;
  if(A%2!=B%2){
    cout<<"IMPOSSIBLE"<<endl;
  }else{
    cout<<(A+B)/2<<endl;
  }
  return 0;
}