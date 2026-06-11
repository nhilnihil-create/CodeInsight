#include<bits/stdc++.h>
using namespace std;

int sorts(int* x,int* y){
  if(*x<*y){
      int temp=*x;
       *x=*y;
       *y=temp;
  }
}
int main(){
    int x,y;
    int ans;
    cin>>x>>y;
    while(x!=y){
      sorts(&x,&y);
      ans=x-y;
      x=ans;
    }
    cout<<x<<endl;
}