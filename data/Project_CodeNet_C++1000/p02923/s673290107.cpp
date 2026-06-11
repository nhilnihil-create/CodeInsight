#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,ans=0,max=0;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(i>0){
      if(a[i]<=a[i-1]){
        ans++;
        if(ans>=max)
        max=ans;
      }else{
        ans=0;
      }
    }
  }
  cout<<max<<endl;
}