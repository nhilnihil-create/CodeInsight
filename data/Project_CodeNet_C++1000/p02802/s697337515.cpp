#include<iostream>

using namespace std;

int main(){
  bool ac[100001]={};
  int pc[100001]={};
  int n,m;
  cin>>n>>m;
  int a=0,pe=0;
  while(m--){
    int p;
    char s[9];
    cin>>p>>s;
    if(s[0]=='A'){
      a+=!ac[p];
      ac[p]=true;
    }else{
      pc[p]+=!ac[p];
    }
  }
  int p=0;
  for(int i=1;i<=n;i++){
    if(ac[i]){
      p+=pc[i];
    }
  }
  cout<<a<<' '<<p<<endl;
}
