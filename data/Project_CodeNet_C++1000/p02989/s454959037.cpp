#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> d(n);
  for(int i=0;i<n;i++){
    cin>>d[i];
  }
  sort(d.begin(),d.end());
  int half=n/2;
  int half2=n/2-1;
  if(d[half]==d[half2]){
    cout<<0<<endl;
    return 0;
  }
  cout<<d[half]-d[half2]<<endl;
}