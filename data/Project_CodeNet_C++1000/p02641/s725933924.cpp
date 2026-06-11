#include<bits/stdc++.h>
using namespace std;

int main(){
  int x,n;
  cin>>x>>n;
  vector<int>a(101);
  vector<int>b(101);
  
  for(int i=1;i<=n;i++){
    cin>>a[i];
    b[a[i]]++;
  }
  
  int ans;
  
  for(int i=0;i<=100;i++){
    if(!b[x-i]){
      ans=x-i;
      break;
    }
    else if(!b[x+i]){
      ans=x+i;
      break;
    }
  }
  cout<<ans<<endl;
}
