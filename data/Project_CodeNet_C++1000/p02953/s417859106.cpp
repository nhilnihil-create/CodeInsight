#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int>Data(n);
  for(int i=0;i<n;i++){
    cin>>Data[i];
  }
  for(int i=n-1;i>0;i--){
    if(Data[i-1]>Data[i]){
      if(Data[i-1]-Data[i]>=2){
        cout<<"No"<<endl;
        //cout<<Data[i-1]<<" "<<Data[i]<<endl;
        return 0;
      }
      Data[i-1]--;
    }
  }
  cout<<"Yes"<<endl;
}