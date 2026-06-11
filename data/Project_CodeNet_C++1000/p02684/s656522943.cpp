#include<iostream>
using namespace std;
int telep[200005][70];
int main(){
  int n;
  long long k;
  cin>>n>>k;
  for(int i=1;i<=n;i++){
    cin>>telep[i][0];
  }
  
  long long cnt=1;
  while(((long long)1<<cnt)<=k){
    for(int i=1;i<=n;i++){
      telep[i][cnt]=telep[telep[i][cnt-1]][cnt-1];
    }
    cnt++;
  }
  
  cnt=0;
  int pos=1;
  while(((long long)1<<cnt)<=k){
    if((k&((long long)1<<cnt))!=0){
      pos=telep[pos][cnt];
    }
    cnt++;
  }
  cout<<pos<<endl;
  return(0);
}