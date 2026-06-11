#include<bits/stdc++.h>
using namespace std;
int main(){
  string table[256],man[256];
  int n,m;
  bool b=true;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>table[i];
  }
  cin>>m;
  for(int i=0;i<m;i++){
    cin>>man[i];
    for(int j=0;j<n;j++){
      if(man[i]==table[j] && b){
	cout<<"Opened"<<" "<<"by"<<" "<<table[j]<<endl;
	b=false;
	break;
      }else if(man[i]==table[j] && !b){
	cout<<"Closed"<<" "<<"by"<<" "<<table[j]<<endl;
	b=true;
	break;
      }
      if(j==n-1) cout<<"Unknown"<<" "<<man[i]<<endl;
    }
  }
  return 0;
}

