#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool saiki(string a,int& i){
  bool hantei=true;
  //cout<<a[i]<<endl;
  int j;
  for(j=i+1;j<a.size();j++){
    if((a[i]=='['&&a[j]==')')||(a[i]=='('&&a[j]==']'))return false;
    if(a[i]=='('&&a[j]==')'){
      i=j;
      return true;
    }
    if(a[i]=='['&&a[j]==']'){
      i=j;
      return true;
    }
    if(a[j]=='('||a[j]=='['){
      hantei=saiki(a,j);
      if(hantei==false)return false;
    }
  }
  return false;
}
int main(){
  string a;
  while(getline(cin,a),a.size()!=1&&a[0]!='.'){
    bool hantei = true;
    for(int i=0;i<a.size();i++){
      if(a[i]==')'||a[i]==']'){hantei=false;break;}
      if(a[i]=='('||a[i]=='['){
	hantei=saiki(a,i);
      }
      if(hantei==false){
	break;
      }
    }
    if(hantei==false)
      cout<<"no"<<endl;
    else
      cout<<"yes"<<endl;
  }
}