#include<iostream>

using namespace std;

int main(){
  int n;
  cin>>n;
  int sub[200001]={};
  for(int i=0;i<n-1;i++){
    int a;
    cin>>a;
    sub[a]++;
  }
  for(int i=1;i<=n;i++){
    cout<<sub[i]<<endl;
  }
}
