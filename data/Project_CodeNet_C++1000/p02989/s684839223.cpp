#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N;
  cin>>N;
  vector<int> d(N);
  for(int i=0;i<N;i++){
    cin>>d[i];
  }
  sort(d.begin(),d.end());
  if(d[N/2]==d[N/2-1]){
    cout<<0<<endl;
  }
  else{
    cout<<d[N/2]-d[N/2-1]<<endl;
  }
}