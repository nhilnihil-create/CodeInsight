#include<iostream>
using namespace std;

int main(){
  int n;cin>>n;
  int ans=0;
  for(int c=1;c<n;++c){
    int ab=n-c;
    int cnt=0;
    for(int i=1;i*i<=ab;++i){
      if(ab%i==0){
        cnt++;
        if(i!=ab/i) cnt++;
      }
    }
    ans+=cnt;
  }
  cout<<ans<<endl;
  return 0;
}