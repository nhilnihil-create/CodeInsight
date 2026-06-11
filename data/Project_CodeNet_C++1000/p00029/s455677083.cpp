#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
vector<string> st;
map<string,int> stm;
main(){
  char hoge[1001];
  string str;
  fgets(hoge,sizeof(hoge),stdin);
  str=hoge;
  int stp=0;
  int n=str.size();
  for(int i=0;i<n;i++){
    if(str.at(i)==' '){
      st.push_back(str.substr(stp,i-stp));
      stp=i+1;
      stm[st.back()]++;
    }
  }
  st.push_back(str.substr(stp,n-stp-1));

  int m=st.size();

  string strmax;
  string stres;
  int count=0;
  int tc=0;
  for(int i=0;i<m;i++){
    if(i==0){
      strmax=st[0];
      stres=st[0];

    }else{
      if(strmax.size() < st[i].size()){
	strmax=st[i];
      } 
      if(stm[st[i]] > stm[stres]){
	stres=st[i];
      }
    }
    
  } 
  cout << stres <<" "<<strmax<<endl;
}