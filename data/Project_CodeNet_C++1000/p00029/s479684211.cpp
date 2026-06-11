#include<iostream>
#include<cstring>
using namespace std;
main(){
  char str[10005][40];
  char cp[100];
  int max=0;
  int mpos=0;
  int saihin=1;
  int spos=0;
  int i=0;
  int ruiseki=1;
  while(cin>>str[i]){
    i++;
  }
  for(int j=0;j<i-1;j++){
    for(int k=i-1;k>j;k--){
      if(strcmp(str[k],str[k-1])<0){
	strcpy(cp,str[k]);
	strcpy(str[k],str[k-1]);
	strcpy(str[k-1],cp);
      }
    }
  }
  for(int j=1;j<i;j++){
    if(strlen(str[j])>max){
      max=strlen(str[j]);
      mpos=j;
    }
    if(strcmp(str[j],str[j-1])==0){
      ruiseki++;
    }
    else{
      ruiseki=1;
    }
    if(ruiseki>saihin){
      saihin=ruiseki;
      spos=j;
    }
  }
  cout<<str[spos]<<" "<<str[mpos]<<endl;
}