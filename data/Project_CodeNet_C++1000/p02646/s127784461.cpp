#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int A,V,C,W,T;
  cin>>A>>V>>C>>W>>T;
  string ans="NO";
  if(W<V){
    int DI=abs(A-C);
    int DC=(V-W)*T;
    if(DI<=DC)ans="YES";
  }
  cout<<ans<<endl;
}