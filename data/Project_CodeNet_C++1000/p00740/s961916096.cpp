#include<iostream>
using namespace std;
#include<vector>
#include<cassert>


int main(){
  while(1){
    int n,p;
    cin>>n>>p;
    if(n==0&&p==0)return 0;
    vector<int> a(n,0);
    int pool=p;
    int i=0;
    while(1){
      for(i = 0;i<n;i++){
        //assert(0<=i && i<n);
        if(pool==0){
          pool+=a[i];
          a[i]=0;
        }else{
          pool--;
          a[i]++;
        }
        //assert(0<=i && i<n);
        if(a[i]==p)break;
      }
      //assert(0<=i && i<n);
      if(a[i]==p&&i<n)break;
    }
    cout<<i<<endl;
  }
  return 0;
}