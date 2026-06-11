#include<bits/stdc++.h>
using namespace std;
typedef pair<long,long> vec;
int main(){
  int N;cin>>N;
  vector<long>X(N),Y(N);for(int i=0;i<N;i++)cin>>X[i]>>Y[i];
  vector<vec> vecs(N*N-N,vec(0,0));
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(i!=j){
        vecs.push_back(vec(X[i]-X[j],Y[i]-Y[j]));
      }
    }
  }
  sort(vecs.begin(),vecs.end());
  int max=0,count=1;
  for(int i=1;i<N*N-N;i++){
    if(vecs[i]==vecs[i-1]){
      count++;
    }
    else{
      if(count>max)max=count;
      count=1;
    }
  }
  cout<<N-max;
}