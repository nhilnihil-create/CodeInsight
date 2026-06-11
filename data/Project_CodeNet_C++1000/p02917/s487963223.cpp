#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int>b(n-1);
  for(int i=0;i<n-1;i++){
    cin>>b.at(i);
  }
  if(n==2){//bがひとつのみ
    cout<<b.at(0)*2;
   return 0;
  }
  vector<int>a(n);
  for(int i=1;i<=n-2;i++){
    if(i==1){//初回
    if(b.at(i-1)>=b.at(i)){
      a.at(i-1)=b.at(i-1);
      a.at(i)=b.at(i);
    }
    else if(b.at(i-1)<b.at(i)){
      a.at(i-1)=a.at(i)=b.at(i-1);
    }
    }
    else{//２回目以降
      if(b.at(i-1)>=b.at(i)){
        a.at(i)=b.at(i);
      }
      else{
        a.at(i)=b.at(i-1);
      }
    }
    if(i==n-2){//〆
        a.at(i+1)=b.at(i);
    }
  }
  int f=0;
  for(int i=0;i<n;i++){
    f+=a.at(i);
  }
  cout<<f;
}
      