#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int A,B,M;
  cin>>A>>B>>M;
  vector<int>a(A);
  vector<int>b(B);
  vector<int>x(M);
  vector<int>y(M);
  vector<int>c(M);
  for(int i=0;i<A;i++){
    cin>>a[i];
  }
  for(int i=0;i<B;i++){
    cin>>b[i];
  }
  for(int i=0;i<M;i++){
    cin>>x[i];
    cin>>y[i];
    cin>>c[i];
  }
  int cnt=0;
  int ans=0;
  for(int i=0;i<M;i++){
    cnt=0;
    cnt=a[x[i]-1]+b[y[i]-1]-c[i];
    if(i==0){
      ans=cnt;
    }
    if(i>0){
      if(cnt<ans){
        ans=cnt;
      }
    }
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  if(ans>a[0]+b[0]){
    ans=a[0]+b[0];
  }   
  cout<<ans<<endl;
}