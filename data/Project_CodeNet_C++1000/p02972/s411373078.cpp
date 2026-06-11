#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int>a(N+1);
  vector<int>b(N+1,0);
  vector<int>c(N+1,0);
  
  for(int i=1;i<N+1;i++){
    cin>>a[i];
  }
  for(int i=N;i>=1;i--){
    if(a[i]==1 && b[i]%2==0){
      c[i]=1;
    }
    else if(a[i]==1 && b[i]%2==1){
      c[i]=0;
    }
    else if(a[i]==0 && b[i]%2==0){
      c[i]=0;
    }
    else if(a[i]==0 && b[i]%2==1){
      c[i]=1;
    }
    if(c[i]==1){
      for(int j=1;j*j<=i;j++){
        if(i%j==0){
          b[j]++;
          if(j*j!=i){
            b[i/j]++;
          }
        }
      }
    }
  }
  
  int ans=0;
  for(int i=1;i<=N;i++){
    if(c[i]==1){
      ans++;
    }
  }
  cout<<ans<<endl;  
  if(ans==0) return 0;
  int temp=ans;
  for(int i=1;i<=N;i++){
    if(c[i]==1 && temp!=1){
      cout<<i<<" ";
      temp--;
    }
    else if(c[i]==1 && temp==1){
      cout<<i<<endl;
    }
  }
  return 0;
}

