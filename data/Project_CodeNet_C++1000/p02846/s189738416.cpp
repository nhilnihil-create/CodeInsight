#include <bits/stdc++.h>
using namespace std;
#define int long long

template<typename T>
void fin(T a){
  cout<<a<<endl;
  exit(0);
}

signed main(){
  int t1,t2,a1,a2,b1,b2;cin>>t1>>t2>>a1>>a2>>b1>>b2;
  a1-=b1;a2-=b2;
  if(a1>0)a1*=-1,a2*=-1;
  int A=t1*a1+t2*a2,B=-t1*a1;
  if(A<0)fin(0);
  if(A==0)fin("infinity");
  int ans=B/A*2+1;
  if(B%A==0)ans--;
  cout<<ans<<endl;
}
/*
あまりがある時　(B/A*2+1)
あまりがない時　(B/A*2)
*/
