#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n;
  cin>>n;
  int vec[n];
  for(int i=0;i<n;i++){
    cin>>vec[i];
  }
  sort(vec,vec+n);
  int p=0;
  for(int i=0;i<n-1;i++){
    if(vec[i]!=vec[i+1]){
      p++;
    }
  }
  if(p==0){
    if(vec[0]==0){
      cout<<"Yes"<<endl;
      return 0;
    }
    cout<<"No"<<endl;
    return 0;
  }
  if(p==1){
    for(int i=0;i<n-1;i++){
      if(vec[i]!=vec[i+1]){
        if(3*(i+1)==n){
          cout<<"Yes"<<endl;
          return 0;
        }
        cout<<"No"<<endl;
        return 0;
      }
    }
  }
  if(p==2){
    for(int i=0;i<n-1;i++){
      if(vec[i]!=vec[i+1]){
        if(3*(i+1)!=n&&3*(i+1)!=2*n){
          cout<<"No"<<endl;
          return 0;
        }
      }
    }
    int x=vec[0],y=vec[n/3],z=vec[n-1];
    int p=x^y^z;
    if(p==0){
      cout<<"Yes"<<endl;
      return 0;
    }
    cout<<"No"<<endl;
    return 0;
  }
  cout<<"No"<<endl;
}