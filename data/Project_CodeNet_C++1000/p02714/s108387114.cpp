#include<bits/stdc++.h>
using namespace std;
int main(){
  int leng;
  cin >>leng;
  map<char,long long>rgb;
  string s;
  cin >>s;
  rgb['R']=0,rgb['G']=0,rgb['B']=0;
  for(int i=0;i<leng;i++){
    rgb.at(s.at(i))++;
  }
  long long tmp=0;
  for(int i=0;i<leng-2;i++){
    for(int j=1;i+j+j<leng;j++){
      if((s.at(i)==s.at(i+j)||s.at(i)==s.at(i+2*j))||s.at(i+j)==s.at(i+2*j)){
        continue;
      }
      else{
        tmp++;
      }
    }
  }
  cout <<rgb.at('R')*rgb.at('G')*rgb.at('B')-tmp<<endl;
}