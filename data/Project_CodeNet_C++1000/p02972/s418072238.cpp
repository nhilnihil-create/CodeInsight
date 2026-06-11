#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n;
  cin>>n;
  int vec[n];
  for(int i=0;i<n;i++){
    cin>>vec[i];
  }
  int ans[n+1]={};
  int vecb[n]={};
  int answer=0;
  for(int i=n-1;i>=0;i--){
    int sum=0;
    for(int j=i+1;j<n+1;j+=i+1){
      sum+=ans[j];
    }
    if(sum%2!=vec[i]){
      vecb[answer]=i+1;
      answer++;
      ans[i+1]=1;
    }
  }
  cout<<answer<<endl;
  for(int i=0;i<answer;i++){
    cout<<vecb[i]<<endl;
  }
}