#include<iomanip>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int main(){
  int n,ans=0;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;++i){
    cin>>a[i];
  }
  int mi=10000000000;
  for(int i=0;i<n;++i){
    if(mi>a[i]){
      mi=a[i];
      ++ans;
    }
  }
  cout<<ans<<endl;
}