#include<bits/stdc++.h>
using namespace std;
int main(){
  uint64_t n;
  cin>>n;
  vector<uint64_t> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  uint64_t curr_max=0;
  uint64_t sum=0;
  for(int i=0;i<n;i++){
    if(curr_max>a[i]){
      sum+=curr_max-a[i];
    }else{
      curr_max=a[i];
    }
  }
  cout<<sum<<endl;
}