#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n;
  cin>>n;
  int x=pow(2,n);
  ll vec[x];
  ll slime[x]={};
  for(int i=0;i<x;i++){
    cin>>vec[i];
  }
  sort(vec,vec+x);
  slime[0]=vec[x-1];
  vec[x-1]=0;
  reverse(vec,vec+x-1);
  for(int i=0;i<n;i++){
    int y=pow(2,i);
    int a=0;
    for(int j=0;j<pow(2,i);j++){
      while(slime[j]<=vec[a]){
        a++;
        if(a>=x){
          cout<<"No"<<endl;
          return 0;
        }
        if(vec[a]==0){
          cout<<"No"<<endl;
          return 0;
        }
      }
      slime[y+j]=vec[a];
      vec[a]=0;
      a++;
    }
    sort(slime,slime+x);
    reverse(slime,slime+x);
    sort(vec,vec+x);
    reverse(vec,vec+x);
  }
  if(vec[0]>0){
    cout<<"No"<<endl;
    return 0;
  }
  if(slime[x-1]==0){
    cout<<"No"<<endl;
    return 0;
  }
  cout<<"Yes"<<endl;
}