#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
  int X[N];
  int Y[N];
  for(int i=0;i<N;i++){
        cin>>X[i]>>Y[i];
  }
    int ans=0;
    for(int i=0;i<N;i++){
       for(int j=0;j<N;j++){
           if(i==j) continue;
           int p=X[i]-X[j];
           int q=Y[i]-Y[j];
           int count=0;
           for(int k=0;k<N;k++){
              for(int l=0;l<N;l++){
                  if(X[k]-X[l]==p&&Y[k]-Y[l]==q)count++;
              }
           }
           ans=max(ans,count);
       }
    }
  cout<<N-ans<<endl;
  return 0;
}