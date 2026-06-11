#include<iostream>
#include<string>
using namespace std;
string a;
int c;
int saiki(int,int);
int main(){
  int ans;
  while(1){
    c=0;
    a.clear();
    getline(cin,a);
    if(a==".")break;
    ans=saiki(0,0);

    //out 
    if(ans==-1)cout << "no" << endl;
    else cout << "yes" << endl;
  }
  return 0;
}
int saiki(int I,int n){//n:1=( 2=[
  for(int i=I;i<a.size();i++){
    if(a[i]=='('){
      i=saiki(i+1,1);
      if(i==-1)return -1;
    }
    else if(a[i]=='['){
      i=saiki(i+1,2);
      if(i==-1)return -1;
    }
    else if(a[i]==')'){
      c++;
      if(n==1){
	c--;
	return i;
      }
    }
    else if(a[i]==']'){
      c++;
      if(n==2){
	c--;
	return i;
      }
    }
    else if(a[i]=='.'){
      if(c!=0)return -1;
      if(n==0)return 0;
    }
  }
  return -1;
  
}