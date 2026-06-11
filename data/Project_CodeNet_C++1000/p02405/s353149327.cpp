#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  while(a!=0&&b!=0){
    for(int i=0;i<a;i++){
      for(int j=0;j<b;j++){
	if((i%2==0&&j%2==0)||(i%2==1&&j%2==1)){
	  cout<<"#";
	}
	else cout<<".";
      }
      cout<<endl;
    }
    cout<<endl;
    cin>>a>>b;
  }
  return 0;
}