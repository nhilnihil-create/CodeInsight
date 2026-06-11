#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  bool num[30]={false};
  int a[30];
  for(int i=0;i<n;i++) {
    cin>>a[i];
  }
  for(int i=0;i<(n-1);++i){
    if(i==0) {
      if(a[0]+1==a[1]) num[0]=true;
    }
    if(a[i]+1==a[i+1]) num[i]=true;
  }
  int sum=0;
  int c[30];
  for(int i=0;i<n;++i) {
    cin>>c[i];
    sum+=c[i];
  }
  for(int i=0;i<(n-1);i++){
    cin>>c[i];
  }
  for(int i=0;i<n;++i){
    if(num[i]==true){
       sum+=c[a[i]-1];
    }
  }
  
  cout<<sum<<endl;
  
}
 
  