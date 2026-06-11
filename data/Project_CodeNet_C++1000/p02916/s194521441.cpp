#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  int a[N],b[N],c[N-1];
  for(int i=0;i<N;i++){
    cin>>a[i];
  }
  for(int i=0;i<N;i++){
    cin>>b[i];
  }
  for(int i=0;i<N-1;i++){
    cin>>c[i];
  }
  int ans=0;
  ans+=b[a[0]-1];
  for(int i=1;i<N;i++){
    ans+=b[a[i]-1];
    if(a[i]-1==a[i-1]){
      ans+=c[a[i]-2];
    }
  }
  cout<<ans<<endl;
}