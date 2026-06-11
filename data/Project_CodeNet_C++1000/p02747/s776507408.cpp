#include <bits/stdc++.h>
using namespace std;
 
int main () {
  string S;
  cin>>S;
  int a=0;
  if(S.size()%2==1){
    a++;}
  for (int i=0;i<S.size();i+=2){
      if(S.at(i)!='h'){
      a++;
  }}
  for (int i=1;i<S.size();i+=2){
      if(S.at(i)!='i'){
      a++;
  }}
  if(a==0){
  cout<<"Yes"<<endl;}
  else
  cout<<"No"<<endl;}
