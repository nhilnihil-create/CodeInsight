//MISHON69
//DATE:6/22/2020
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k,q;
  cin>>n>>k>>q;
  map<int,int>m;
  for(int i=0;i<q;i++){
    int temp;
    cin>>temp;
    m[temp]++;
  }
  for(int i=1;i<=n;i++){
    if((q-m[i])<k)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
  }
}  
