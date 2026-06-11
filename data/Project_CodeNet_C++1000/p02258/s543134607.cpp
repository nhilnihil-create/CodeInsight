#include<bits/stdc++.h>
using namespace std;
main(){
  long long n,a;
  long long mins,FXmaxs=INT_MIN;
  cin>>n;
  cin>>mins;
  for(int i=1;i<n;i++){
    cin>>a;
    FXmaxs=max(FXmaxs,a-mins);
    mins=min(mins,a);
  }
  cout<<FXmaxs<<endl;
}