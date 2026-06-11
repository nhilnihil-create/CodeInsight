#include<bits/stdc++.h>
using namespace std;
int main(){
  string str;cin>>str;
  int num=0;
  int size=str.size();
  vector<string>s;
  vector<int>kiroku;
  vector<int>ans(size,0);
  while(num<size){
    string tmp;
    int flag=0;
    while(1){
      if(num==size){
        s.push_back(tmp);
        break;
      }
      if(str.at(num)=='R'&&flag==0){
        tmp.push_back(str.at(num));
        num++;
      }
      else if(str.at(num)=='L'&&flag==0){
        tmp.push_back(str.at(num));
        kiroku.push_back(num);
        num++;
        flag=1;
      }
      else if(str.at(num)=='L'&&flag==1){
        tmp.push_back(str.at(num));
        num++;
        flag=1;
      }
      else if(str.at(num)=='R'&&flag==1){
        s.push_back(tmp);
        flag=0;
        break;
      }
    }
  }
  int s_size=s.size();
  int sizetmp=0;
  for(int i=0;i<s_size;i++){
    int roopsize=s.at(i).size();
    for(int j=0;j<roopsize;j++){
      int jj=j+sizetmp;
      if(jj==kiroku.at(i)){
        ans.at(jj)=(kiroku.at(i)-sizetmp)/2+(roopsize+sizetmp-1-kiroku.at(i))/2+1;
      }
      else if(jj==(kiroku.at(i)-1)){
        ans.at(jj)=(kiroku.at(i)-1-sizetmp)/2+(roopsize+sizetmp-1-kiroku.at(i)+1)/2+1;
      }
      if(j==roopsize-1)sizetmp+=roopsize;
    }
  }
  for(int i=0;i<size;i++){
    cout <<ans.at(i)<<endl;
  }
}