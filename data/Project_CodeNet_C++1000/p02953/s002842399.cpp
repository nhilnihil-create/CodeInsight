#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int>h(n);
  for(int i=0;i<n;i++){
    cin>>h[i];
  }
  h[0]--;
  for(int i=1;i<n;i++){
    if(h[i]<h[i-1]){
      cout<<"No"<<endl;
      return 0;
    }
    else if(h[i]>h[i-1]){
      h[i]--;
    }
  }
  cout<<"Yes"<<endl;
}
      
      
